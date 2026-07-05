#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N = 1001;

int arr[N][N]{}, dp[4][N][N]{};
int n, m;

void printDp(int x)
{
    return;
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << dp[x][i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void F()
{
    // dp1 max cal from 1,1 to x,y
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dp[0][i][j] = max((i > 0 ? dp[0][i - 1][j] : 0), (j > 0 ? dp[0][i][j - 1] : 0)) + arr[i][j];
        }
    }

    printDp(0);

    // dp1 max cal from 1,1 to x,y
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            dp[1][i][j] = max((i < n - 1 ? dp[1][i + 1][j] : 0), (j == m - 1 ? 0 : dp[1][i][j + 1])) + arr[i][j];
        }
    }
    printDp(1);

    // dp1 max cal from 1,1 to x,y
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < m; ++j)
        {
            dp[2][i][j] = max((i == n - 1 ? 0 : dp[2][i + 1][j]), (j == 0 ? 0 : dp[2][i][j - 1])) + arr[i][j];
        }
    }
    printDp(2);

    // dp1 max cal from 1,1 to x,y
    for (int i = 0; i < n; ++i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            dp[3][i][j] = max((i == 0 ? 0 : dp[3][i - 1][j]), (j == m - 1 ? 0 : dp[3][i][j + 1])) + arr[i][j];
        }
    }
    printDp(3);

    int ans = 0;
    // possible meeting points
    for (int i = 1; i < n - 1; ++i)
        for (int j = 1; j < m - 1; ++j)
        {
            // boy from left and girl from dow
            int op1 = dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i - 1][j];
            //  opption 2
            int op2 = dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] + dp[3][i][j + 1];

            ans = max(ans, max(op1, op2));
        }

    cout << ans << endl;
}

int32_t main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];
    }

    F();
}