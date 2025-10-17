#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
    bool is_square(ll x)
    {
        if (x < 0)
            return false;
        ll s = (ll)(sqrt((double)x) + 0.5);
        return s * s == x;
    }

    vector<pair<ll, ll>> get_divisors(ll delta)
    {
        vector<pair<ll, ll>> v;
        for (ll i = 1; i * i <= delta; i++)
        {
            if (delta % i == 0)
                v.emplace_back(i, delta / i);
        }
        return v;
    }

public:
    void solve()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            if (n == 2)
            {
                cout << -1 << '\n';
                continue;
            }
            ll N = (ll)n * (n + 1) / 2;
            bool found = false;
            int c = -1;
            for (int i = 1; i <= n; i++)
            {
                ll s = (ll)i * (N - i);
                if (is_square(s))
                {
                    found = true;
                    c = i;
                    break;
                }
            }
            if (found)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (i != c)
                        cout << c << " " << i << '\n';
                }
                continue;
            }
            ll S0 = N - 1;
            ll sqr = (ll)ceil(sqrt((double)S0));
            bool done = false;
            int j = -1, k = -1;
            ll curr = sqr;
            for (int it = 0; it < 100; it++)
            {
                ll target = curr * curr;
                ll delta = target - S0;
                if (delta < 3)
                {
                    curr++;
                    continue;
                }
                auto dvs = get_divisors(delta);
                bool ok = false;
                for (auto [d, jj] : dvs)
                {
                    if (d >= 1 && d <= n - 1 && jj >= 2 && jj <= n && jj != d + 1)
                    {
                        j = (int)jj;
                        k = (int)(d + 1);
                        ok = true;
                        break;
                    }
                }
                if (ok)
                {
                    done = true;
                    break;
                }
                curr++;
            }
            if (!done)
            {
                cout << -1 << '\n';
                continue;
            }
            for (int i = 2; i <= n; i++)
            {
                if (i == j)
                    continue;
                cout << "1 " << i << '\n';
            }
            cout << k << " " << j << '\n';
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution ob;
    ob.solve();
    return 0;
}
