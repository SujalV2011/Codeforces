#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        vector<int> hasColor(n * m, 0);
        vector<int> hasBad(n * m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                hasColor[a[i][j] - 1] = 1;

                if (i + 1 < n && a[i][j] == a[i + 1][j])
                {
                    hasBad[a[i][j] - 1] = 1;
                }

                if (j + 1 < m && a[i][j] == a[i][j + 1])
                {
                    hasBad[a[i][j] - 1] = 1;
                }
            }
        }

        int colorCount = 0, badCount = 0, maxBad = 0;
        for (int i = 0; i < n * m; i++)
        {
            colorCount += hasColor[i];
            badCount += hasBad[i];
            maxBad = max(maxBad, hasBad[i]);
        }

        cout << colorCount + badCount - 1 - maxBad << endl;
    }

    return 0;
}
