// https://atcoder.jp/contests/dp/tasks/dp_h
#include <iostream>
using namespace std;
const int N = 1001;
const int MOD = 1e9 + 7;
int arr[N][N];

void dp_from_back(int n, int m)
{
    if (!arr[0][0] or !arr[n - 1][m - 1])
        return;

    // for (int i = n - 1; i >= 0; --i)
    // {
    //     if (arr[i][m - 1] == 0)
    //     {
    //         while ((--i) >= 0)
    //         {
    //             arr[i][m - 1] = 0;
    //         }
    //     }
    // }

    // for (int j = m - 1; j >= 0; --j)
    // {
    //     if (arr[n - 1][j] == 0)
    //     {
    //         while ((--j) >= 0)
    //             arr[n - 1][j] = 0;
    //     }
    // }

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (arr[i][j] == 0)
                arr[i][j] = 0;
            else if (i == n - 1)
                arr[i][j] = (arr[i][j + 1] % MOD) % MOD;
            else if (j == m - 1)
                arr[i][j] = (arr[i + 1][j] % MOD) % MOD;
            else
                arr[i][j] = (arr[i + 1][j] % MOD + arr[i][j + 1] % MOD) % MOD;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    char x;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            if (x == '.')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }

    dp_from_back(n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << arr[0][0] << endl;
}