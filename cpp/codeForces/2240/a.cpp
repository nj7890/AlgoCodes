#include <iostream>
using namespace std;

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint64_t n, k;
        cin >> n >> k;

        uint64_t canAdd = k, cost = 1, ans = 0;

        while (n >= cost and canAdd > 0)
        {
            canAdd = min(k, n / cost);
            ans += canAdd;
            n -= canAdd * cost;
            cost <<= 1;
            ;
        }
        cout << ans << endl;
    }
}