#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int N = 200003;
vector<int> tree[N]{};
int dp[N][2]{};

void F(int node, int parent)
{
    int matching = 0;
    // intialize matching with zero
    dp[node][0] = dp[node][1] = 0;
    int leaf = 1;
    // dp[i][0]
    //  Build DP in O(n)
    for (const int &child : tree[node])
    {
        if (child == parent)
            continue;
        F(child, node);
        leaf = 0;
        // dp[node][0] = max({dp[node][0],dp[child][0],dp[child][1]});
    }

    // if we at leaf node
    // F(node,parent)
    if (leaf)
    {
        // Because the dp has been done abvoe, matching of leaf node is zero
        return;
    }

    // No Now leaf nodes, this node had child, so we've to update the dp[node][0] and dp[node][1];
    int totalSum = 0;
    vector<int> prefix, suffix;
    for (const int &child : tree[node])
        if (child != parent)
        {
            //  current child ki matching stored in prefix and suffix
            int mi = max(dp[child][0], dp[child][1]);
            totalSum += mi;
            prefix.push_back(mi);
            suffix.push_back(mi);
        }
    //  build prefix and suffix
    for (int i = 1; i < prefix.size(); ++i)
        prefix[i] += prefix[i - 1];

    for (int i = suffix.size() - 2; i >= 0; --i)
        suffix[i] += suffix[i + 1];

    dp[node][0] = suffix[0];
    dp[node][1] = 0;
    int i = 0;

    for (const int &child : tree[node])
    {
        if (child == parent)
            continue;
        dp[node][1] = max(dp[node][1], (1 + dp[child][0] + ((i == suffix.size() - 1) ? 0 : suffix[i + 1]) + (i == 0 ? 0 : prefix[i - 1])));
        ++i;
    }
}

int main()
{
    int n;
    cin >> n;
    int x, y;
    for (int i = 2; i <= n; ++i)
    {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    F(1, 0);

    cout << max(dp[1][0], dp[1][1]);
}