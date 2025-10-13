#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    int t;
	cin >> t;
	while (t--) 
    {
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for (int i=0;i<n;i++) cin >> a[i];

		map<ll, ll> cnt;
		ll mx = 0;
		for (auto &it : a) 
        {
			if (it % k == 0) continue;
			cnt[k - it % k]++;
			mx = max(mx, cnt[k - it % k]);
		}

		ll ans = 0;
		for (auto [key, val] : cnt) 
        {
			if (val == mx) 
            {
				ans = k * 1LL * (val - 1) + key + 1;
			}
		}

		cout << ans << endl;
        
	}
	return 0;
}