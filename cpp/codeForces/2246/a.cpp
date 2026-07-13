#include <iostream>
using namespace std;

int main()
{
    int32_t t;
    cin >> t;
    while (t--)
    {
        int32_t n;
        cin >> n;

        for (int_fast32_t i = n; i >= 1; i--)
            cout << i << " ";
        cout << endl;
    }
}