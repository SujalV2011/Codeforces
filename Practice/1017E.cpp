#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n; 
        cin >> n;
        ll arr[n+1];
        vector<ll> cnt(30, 0);
        for (int i = 1; i <= n; i++) 
        {
            cin >> arr[i];
            for (int j = 0; j < 30; j++) 
            {
                cnt[j] += ((arr[i] >> j) & 1);
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) 
        {
            ll tot = 0;
            for (int j = 0; j < 30; j++) 
            {
                bool f = ((arr[i] >> j) & 1);
                if (f) tot += (1 << j) * (n - cnt[j]);
                else tot += (1 << j) * cnt[j];
            }
            ans = max(ans, tot);
        }
        cout << ans << "\n";
    }
}
