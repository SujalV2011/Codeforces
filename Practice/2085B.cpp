#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        vector<pair<ll, ll>> op;
        ll mid = n / 2;
        ll r = n;

        bool zeroInRight = false;
        for (int i = mid; i < n; ++i)
        {
            if (a[i] == 0)
            {
                zeroInRight = true;
                break;
            }
        }
        if (zeroInRight)
        {
            op.push_back({mid + 1, n});
            r -= n - mid - 1;
        }

        bool zeroInLeft = false;
        for (int i = 0; i < mid; ++i)
        {
            if (a[i] == 0)
            {
                zeroInLeft = true;
                break;
            }
        }
        if (zeroInLeft)
        {
            op.push_back({1, mid});
            r -= mid - 1;
        }

        op.push_back({1, r});

        cout << op.size() << '\n';
        for (auto p : op)
        {
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}
