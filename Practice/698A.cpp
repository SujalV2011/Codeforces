#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> d(n + 1, vector<int>(3, -1e9));
    d[0][0] = 0;

    for (int i = 1; i <= n; i++) 
    {
        // rest
        d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
        
        // contest
        if (a[i] == 1 || a[i] == 3) 
        {
            d[i][1] = max(d[i-1][0], d[i-1][2]) + 1;
        }
        // gym
        if (a[i] == 2 || a[i] == 3) 
        {
            d[i][2] = max(d[i-1][0], d[i-1][1]) + 1;
        }
    }

    int mx = max({d[n][0], d[n][1], d[n][2]});
    cout << n - mx << endl;

    return 0;
}
