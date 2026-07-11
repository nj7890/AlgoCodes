#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int N = 200003;

vector<int> tree[N]{};
vector<int> dp(N,0);

void F()
{
    set<int> s;
    queue<int> q;
    int node = 1, parent =0;
    q.push(node);
    dp[node] = 0;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        s.insert(node);
        for (const int &child : tree[node]){
            q.push(child);

        }
    }
}

int Solve(int node, int parent)
{
    //  current state
    int subordinates = 0;
    // cout<<"Node: "<<node<<endl;
    //  current node k child pr jaana hai and uske child pr formula apply krna hai
    for (const int &child : tree[node])
    {
        if (child != parent)
        {
            // Solve(child, node);
            subordinates += 1 + (dp[child] = 
                Solve(child, node));
        }
    }
    return dp[node] = subordinates;
}

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 2; i <= n; ++i)
    {
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    Solve(1, 0);

    for (int i = 1; i <= n; ++i)
        cout << dp[i] << " ";
    cout << endl;
    // F();
}