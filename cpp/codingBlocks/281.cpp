#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5001;
int a[N], b[N], dp[N][N]{};
int n, m;

int F(int x, int y)
{
    // stoping point
    if (x == n)
        return 0;
    if (x > n or y >= m)
        return 1e8;
    if (dp[x][y] != 0)
        return dp[x][y];
    return dp[x][y] = min(abs(a[x] - b[y]) + F(x + 1, y + 1), F(x, y + 1));
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);

    cout << F(0, 0) << endl;
}