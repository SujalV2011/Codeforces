#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        vector<ll> pa(n + 1, 0), pb(m + 1, 0);
        for (int i = 0; i < n; i++) pa[i + 1] = pa[i] + a[i];
        for (int i = 0; i < m; i++) pb[i + 1] = pb[i] + b[i];

        int Z = n + m;
        vector<ll> best(Z + 1, 0);
        vector<int> ibest(Z + 1, 0);

        int ia = 0, ibp = 0;
        ll s = 0;
        best[0] = 0;
        ibest[0] = 0;
        for (int z = 1; z <= Z; z++)
        {
            if (ia < n && (ibp >= m || a[ia] >= b[ibp]))
            {
                s += a[ia];
                ia++;
            }
            else
            {
                s += b[ibp];
                ibp++;
            }
            best[z] = s;
            ibest[z] = ia;
        }

        while (q--)
        {
            int x, y, z;
            cin >> x >> y >> z;

            int L = max(0, z - y);
            int U = min(z, x);

            ll ans;
            if (ibest[z] < L)
            {
                ans = pa[L] + pb[z - L];
            }
            else if (ibest[z] > U)
            {
                ans = pa[U] + pb[z - U];
            }
            else
            {
                ans = best[z];
            }

            cout << ans << "\n";
        }
    }
    return 0;
}
