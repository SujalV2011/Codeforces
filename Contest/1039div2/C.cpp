#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int64_t> b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }

        bool ok = true;
        int64_t pref_min = b[0];
        for (int i = 1; i < n; ++i)
        {
            if (b[i] > 2 * pref_min - 1)
            {
                ok = false;
                break;
            }
            pref_min = min(pref_min, b[i]);
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}