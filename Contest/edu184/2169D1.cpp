/*
    x=2 y=3 
    1 2 3 4 5 6 7 8 9 10
    1 2 4 5 7 8 10 11 13 14
    1 2 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int t;
    cin >> t;
    while(t--) 
    {
        ll x, y, k;
        cin >> x >> y >> k;

        ll lo = 1, hi = (ll)1e12, ans = -1;

        {
            ll n = hi;
            for(ll i = 0; i < x; i++) 
            {
                ll del = n / y;
                if(del == 0) break;
                n -= del;
            }
            if(n < k) 
            {
                cout << -1 << endl;
                continue;
            }
        }

        while(lo <= hi) 
        {
            ll mid = (lo + hi) >> 1;

            ll n = mid;
            for(ll i = 0; i < x; i++) 
            {
                ll del = n / y;
                if(del == 0) break;
                n -= del;
            }

            if(n >= k) 
            {
                ans = mid;
                hi = mid - 1;
            } 
            else 
            {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
