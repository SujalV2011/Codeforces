#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<pair<int,int>> ans;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
            if (a[i][j] * a[i][j+1] * a[i+1][j] * a[i+1][j+1] > 0) 
            {
                a[i][j] = 2;
                a[i][j+1] = 2;
                a[i+1][j] = 2;
                a[i+1][j+1] = 2;
                ans.push_back({i+1, j+1});
            }

    bool invalid = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 1)
                invalid = true;

    if (invalid) 
    {
        cout << -1 << "\n";
    } 
    else 
    {
        cout << ans.size() << "\n";
        for (auto &p : ans)
            cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
