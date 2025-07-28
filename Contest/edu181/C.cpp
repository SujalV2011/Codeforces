#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll count(ll x)
{
    int bad[] = {2, 3, 5, 7};
    ll res = 0;
    for (int mask = 1; mask < (1 << 4); mask++)
    {
        ll prod = 1;
        bool overflow = false;
        for (int i = 0; i < 4; i+=1)
        {
            if (mask & (1 << i))
            {
                if (__builtin_mul_overflow(prod, (ll)bad[i], &prod))
                {
                    overflow = true;
                    break;
                }
            }
        }
        if (overflow) continue;
        ll cnt = x / prod;
        if (__builtin_popcount(mask) % 2 == 1) res += cnt;
        else res -= cnt;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << (r - count(r)) - (l - 1 - count(l - 1)) << '\n';
    }
    return 0;
}
