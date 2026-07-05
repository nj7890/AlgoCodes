// 2D prefix
#include <iostream>
using namespace std;

const int N = 100;
int n, m;
int arr[N][N]{}, pre[N][N]{};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    // prefix sum using Ven Diagram Formula

    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            pre[i][j] = arr[i][j];
            if (i > 0)
                pre[i][j] += pre[i - 1][j];
            if (j > 0)
                pre[i][j] += pre[i][j - 1];
            if (i > 0 && j > 0)
                pre[i][j] -= pre[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
}