#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        ll a;
        cin >> n >> a;
        vector<ll> v(n);
        for(ll &x : v) cin >> x;

        int less_cnt = lower_bound(v.begin(), v.end(), a) - v.begin();
        int greater_cnt = n - (upper_bound(v.begin(), v.end(), a) - v.begin());

        if(less_cnt == 0 && greater_cnt == 0) 
        {
            cout << 0 << "\n";
            continue;
        }

        if(less_cnt > greater_cnt) cout << a - 1 << "\n";
        else cout << a + 1 << "\n";
    }
    return 0;
}
