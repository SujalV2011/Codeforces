#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    ll ans = 0;
    for (int i = 0; i < n; i++) 
    {
        ll cur = a[i];
        auto it = lower_bound(b.begin(), b.end(), cur);
        ll dist = LLONG_MAX;
        if (it != b.end()) dist = *it - cur;
        if (it != b.begin()) 
        {
            it--;
            dist = min(dist, cur - *it);
        }
        ans = max(ans, dist);
    }

    cout << ans;
    return 0;
}
