#include <iostream>
#define int long long
using namespace std;

const int MOD = 1000000000 + 7;
const int K = 100000 + 5;
// dp[i][j] = No of ways to distribute j candies among i childers
int dp[101][K]{};
int a[101]{};

int n=0, k=0;

int F()
{
    /*
        base condition: dp[1][j] = 1/0;
        j in eange [0,k]
    */
    for (int j = 0; j <= k; ++j)
    {
        if (j <= a[1])
        {
            dp[1][j] = 1;
        }
        else
            dp[1][j] = 0;
        // cout<<dp[1][j]<<" ";
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            // ith child ko j candies distrbution
            int limit = min(a[i], j);
            for (int x = 0; x <= limit; ++x)
            {
                dp[i][j] = (dp[i][j] % MOD + dp[i - 1][j - x] % MOD) % MOD;
            }
        }
    }
    return (dp[n][k])%MOD;
}


int F1()
{
    /*
        base condition: dp[1][j] = 1/0;
        j in eange [0,k]
    */
    for (int j = 0; j <= k; ++j)
    {
        if (j <= a[1])
        {
            dp[1][j] = 1;
        }
        else
            dp[1][j] = 0;
        // cout<<dp[1][j]<<" ";
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            // ith child ko j candies distrbution
            int p1=0;
            if(j>0)
                p1 = dp[i][j-1] % MOD;
            int p2=0;
            if(j>a[i])
                p2 = dp[i-1][j-a[i]-1]%MOD;
            int p3 = dp[i-1][j]%MOD;
            dp[i][j] = (p1-p2+p3)%MOD;

        }
    }
    return (dp[n][k])%MOD;
}

int32_t main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cout << F1() << endl;
}