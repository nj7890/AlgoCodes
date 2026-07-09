#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;
    string prev{""}, sp, ep;
    map<pair<string, string>, int> mp;
    int ctc = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> sp >> ep;
        if (sp == prev)
            ctc = b;
        else
            ctc = a;
        prev = ep;
        if (sp > ep)
            swap(sp, ep);
        mp[{sp, ep}] += ctc;
    }

    vector<int> cost;
    long long TotalCost = 0;
    for (pair<pair<string, string>, int> x : mp)
    {
        TotalCost += x.second;
        cost.push_back(x.second);
    }
    // Sort cost in descending order
    // sort(cost.begin(),cost.end(),greater<int>());

    // sort(cost.begin(),cost.end());
    // reverse(cost.begin(),cost.end());

    sort(cost.rbegin(), cost.rend());
    //  we try to but all the cards for all trip we are allowed for
    for (int i = 0; i < cost.size() and i < k; ++i)
    {
        if (cost[i] > f)
        {
            TotalCost = TotalCost - cost[i] + f;
        }
        else
        {
            break;
        }
    }

    cout << TotalCost << endl;

    return 0;
}