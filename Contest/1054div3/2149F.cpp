#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll h, d;
        cin >> h >> d;

        ll lo = 1, hi = d + 1;
        while (lo < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll q = d / mid;
            ll r = d % mid;
            ll sumT = r * (q + 1) * (q + 2) / 2 + (mid - r) * q * (q + 1) / 2;
            ll rhs = h + mid - 2;
            if (sumT <= rhs) hi = mid;
            else lo = mid + 1;
        }

        ll ans;
        if (lo <= d)    ans = d + (lo - 1);
        else
        {
            ll r = d % d;
            ll q = d / d;
            ll sumT = r * (q + 1) * (q + 2) / 2 + (d - r) * q * (q + 1) / 2;
            ll needRest = sumT - h + 1;
            if (needRest < 0) needRest = 0;
            ll restBetween = d - 1;
            ll R_total = max(needRest, restBetween);
            ans = d + R_total;
        }
        cout << ans << endl;
    }
    return 0;
}
