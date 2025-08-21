#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 21;
    vector<ll> p3(M), c(M);

    p3[0] = 1;
    for (int i = 1; i < M; i++)
        p3[i] = p3[i - 1] * 3;

    for (int i = 0; i < M; i++)
    {
        if (i == 0) c[i] = 3;
        else if (i + 1 < M) c[i] = p3[i + 1] + 1LL * i * p3[i - 1];
        else c[i] = LLONG_MAX / 4;
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> cnt(M, 0);
        cnt[0] = n;
        ll d = n;`
        ll ans = n * c[0];

        for (int i = 0; i < M - 1 && d > k; i++)
        {
            ll m = cnt[i] / 3;
            if (m > 0)
            {
                ll red = m * 2;
                if (d - red < k)
                {
                    ll need = d - k;
                    m = (need + 1) / 2;
                }
                cnt[i] -= m * 3;
                cnt[i + 1] += m;
                d -= m * 2;
                ans += m * (c[i + 1] - 3 * c[i]);
            }
        }

        if (d > k) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
