#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1001;
int arr[N][N];
int n, m;

int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        arr[x][y] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            arr[i][j] += arr[i - 1][j];
        }
    }
    // prefix done
    int value = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 1; j < n - 1; ++j)
        {

            int d1 = arr[i][j];
            int d2 = arr[i][n - 1] - d1;
            int d3 = arr[n - 1][j] - d1;
            int d4 = arr[n - 1][n - 1] - d2 - d3 - d1;
            cout<<min({d1, d2, d3, d4})<<endl;
            int value = max(value, min({d1, d2, d3, d4}));
        }
    }

    cout << value << endl;
}