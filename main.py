#!/usr/bin/env python3
import os
import argparse
import numpy as np
import pandas as pd
from tqdm import tqdm

from sklearn.model_selection import KFold
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import Ridge
from sklearn.pipeline import Pipeline
from sklearn.metrics import make_scorer

def smape(y_true, y_pred):
    y_true = np.asarray(y_true, dtype=float)
    y_pred = np.asarray(y_pred, dtype=float)
    denom = (np.abs(y_true) + np.abs(y_pred)) / 2.0
    out = np.zeros_like(denom)
    mask = denom > 0
    out[mask] = np.abs(y_true[mask] - y_pred[mask]) / denom[mask]
    # where denom==0, treat as 0 error (y_true==y_pred==0)
    return np.mean(out) * 100.0

def build_pipeline(max_features=50000, min_df=3, ngram_range=(1,2), alpha=1.0):
    # Ridge is trained on log1p(price); custom wrapper to apply log transform
    from sklearn.base import BaseEstimator, RegressorMixin

    class LogRidge(RegressorMixin, BaseEstimator):
        def __init__(self, alpha=1.0, random_state=42):
            self.alpha = alpha
            self.random_state = random_state
            self.model = Ridge(alpha=self.alpha, random_state=self.random_state)

        def fit(self, X, y):
            y_log = np.log1p(y.astype(float))
            self.model.fit(X, y_log)
            return self

        def predict(self, X):
            pred_log = self.model.predict(X)
            pred = np.expm1(pred_log)
            pred = np.clip(pred, 0.0, None)  # no negatives
            return pred

    tfidf = TfidfVectorizer(
        max_features=max_features,
        min_df=min_df,
        ngram_range=ngram_range,
        strip_accents="unicode",
        lowercase=True,
        token_pattern=r"(?u)\b\w+\b"
    )
    model = LogRidge(alpha=alpha, random_state=42)
    pipe = Pipeline([
        ("tfidf", tfidf),
        ("ridge", model),
    ])
    return pipe

def cross_validate_text_only(train_df, text_col="catalog_content", target_col="price",
                             n_splits=5, max_features=50000, min_df=3, ngram_range=(1,2), alpha=1.0,
                             seed=42):
    X = train_df[text_col].fillna("").astype(str).values
    y = train_df[target_col].astype(float).values

    kf = KFold(n_splits=n_splits, shuffle=True, random_state=seed)
    oof = np.zeros(len(train_df), dtype=float)
    smapes = []

    for fold, (tr_idx, va_idx) in enumerate(kf.split(X), 1):
        X_tr, y_tr = X[tr_idx], y[tr_idx]
        X_va, y_va = X[va_idx], y[va_idx]

        pipe = build_pipeline(max_features=max_features, min_df=min_df, ngram_range=ngram_range, alpha=alpha)
        pipe.fit(X_tr, y_tr)
        preds = pipe.predict(X_va)
        fold_smape = smape(y_va, preds)
        smapes.append(fold_smape)
        oof[va_idx] = preds
        print(f"Fold {fold}/{n_splits} SMAPE: {fold_smape:.3f}%")

    print(f"CV SMAPE: mean={np.mean(smapes):.3f}% std={np.std(smapes):.3f}%")
    return oof, smapes

def fit_full_and_predict(train_df, test_df, text_col="catalog_content", target_col="price",
                         max_features=50000, min_df=3, ngram_range=(1,2), alpha=1.0):
    X_train = train_df[text_col].fillna("").astype(str).values
    y_train = train_df[target_col].astype(float).values
    X_test = test_df[text_col].fillna("").astype(str).values

    pipe = build_pipeline(max_features=max_features, min_df=min_df, ngram_range=ngram_range, alpha=alpha)
    pipe.fit(X_train, y_train)
    preds_test = pipe.predict(X_test)
    return preds_test

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--train_csv", type=str, required=True, help="Path to train.csv")
    parser.add_argument("--test_csv", type=str, required=True, help="Path to test.csv")
    parser.add_argument("--out_csv", type=str, default="submission.csv")
    parser.add_argument("--text_col", type=str, default="catalog_content")
    parser.add_argument("--target_col", type=str, default="price")
    parser.add_argument("--max_features", type=int, default=50000)
    parser.add_argument("--min_df", type=int, default=3)
    parser.add_argument("--alpha", type=float, default=1.0)
    parser.add_argument("--n_splits", type=int, default=5)
    args = parser.parse_args()

    train_df = pd.read_csv(args.train_csv)
    test_df = pd.read_csv(args.test_csv)

    # sanity checks
    assert args.text_col in train_df.columns and args.text_col in test_df.columns
    assert args.target_col in train_df.columns
    assert "sample_id" in train_df.columns and "sample_id" in test_df.columns

    print("Running 5-fold CV (text-only TF-IDF + Ridge)...")
    _, _ = cross_validate_text_only(
        train_df,
        text_col=args.text_col,
        target_col=args.target_col,
        n_splits=args.n_splits,
        max_features=args.max_features,
        min_df=args.min_df,
        ngram_range=(1, 2),
        alpha=args.alpha
    )

    print("Training on full data and predicting test...")
    preds = fit_full_and_predict(
        train_df, test_df,
        text_col=args.text_col,
        target_col=args.target_col,
        max_features=args.max_features,
        min_df=args.min_df,
        ngram_range=(1, 2),
        alpha=args.alpha
    )

    sub = pd.DataFrame({"sample_id": test_df["sample_id"], "price": preds.astype(float)})
    sub.to_csv(args.out_csv, index=False)
    print(f"Saved submission to {args.out_csv}")

if __name__ == "__main__":
    main()
