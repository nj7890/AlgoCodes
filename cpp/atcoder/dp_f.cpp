#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 3001;

int dp[N][N];
// dp(x,y) is the length of the longest sub string from x to n and y to j.

string getlcs(string &s, string &t, int len)
{
    string ans = "";

    int i = 0, j = 0;

    while (len > 0)
    {
        if (s[i] == t[j])
        {
            ans.push_back(s[i]);
            i++;
            j++;
            len--;
        }
        else
        {
            if (dp[i + 1][j] > dp[i][j + 1])
            {
                i++;
            }
            else
                j++;
        }
    }
    return ans;
}

int lengthLCS(string &s, string &t, int i, int j)
{
    if (i >= s.length() or j >= t.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = {1 + lengthLCS(s, t, i + 1, j + 1)};
    else
    {
        int op1 = lengthLCS(s, t, i + 1, j);
        int op2 = lengthLCS(s, t, i, j + 1);
        return dp[i][j] = max(op1, op2);
    }
}

string Solve(string &s, string &t)
{
    memset(dp, -1, sizeof(dp));
    int len = lengthLCS(s, t, 0, 0);
    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = 0; j < t.length(); ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return getlcs(s, t, len);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << Solve(s, t) << endl;
}