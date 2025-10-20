from functools import lru_cache

MOD = 10**9 + 7

# ---------- Safe Combination (No factorial precompute) ----------
@lru_cache(maxsize=None)
def comb(n, k):
    if k < 0 or k > n:
        return 0
    if k == 0 or k == n:
        return 1
    k = min(k, n - k)
    res = 1
    for i in range(1, k + 1):
        res = res * (n - i + 1) % MOD
        res = res * pow(i, MOD - 2, MOD) % MOD
    return res

# ---------- Prime Factorization ----------
def factors(x):
    r = []
    d = 2
    while d * d <= x:
        if x % d == 0:
            c = 0
            while x % d == 0:
                x //= d
                c += 1
            r.append((d, c))
        d += 1 if d == 2 else 2
    if x > 1:
        r.append((x, 1))
    return r

# ---------- Main Solve ----------
def solve(N, A, B):
    P = factors(B)
    if not P:
        return 0

    vals = []
    for p, e in P:
        arr = []
        for k in range(e + 1):
            x = comb(k + N - 1, N - 1)
            y = comb((e - k) + N - 1, N - 1)
            arr.append((x, y))
        vals.append(arr)

    # Precompute powers only up to necessary limit
    powers = []
    for p, e in P:
        pw = [1]
        v = 1
        for _ in range(e):
            v *= p
            if v > A:
                break
            pw.append(v)
        powers.append(pw)

    ans = 0
    stack = [(0, 1, 1)]  # (index, val, prod)
    while stack:
        i, val, prod = stack.pop()
        if val > A:
            continue
        if i == len(P):
            ans = (ans + prod) % MOD
            continue

        p, e = P[i]
        arr = vals[i]
        pw = powers[i]
        max_k = min(e, len(pw) - 1)
        for k in range(max_k + 1):
            nxt = val * pw[k]
            if nxt > A:
                break
            x, y = arr[k]
            new_prod = prod * x % MOD * y % MOD
            stack.append((i + 1, nxt, new_prod))

    return ans % MOD

# ---------- I/O ----------
def main():
    with open("/content/final_product_chapter_2_input.txt", "r") as fin:
        t = int(fin.readline().strip())
        tests = [tuple(map(int, fin.readline().split())) for _ in range(t)]

    results = []
    for i, (N, A, B) in enumerate(tests, 1):
        res = solve(N, A, B)
        results.append(f"Case #{i}: {res}")

    with open("/content/final_product_chapter_2_output.txt", "w") as fout:
        fout.write("\n".join(results))

if __name__ == "__main__":
    main()
