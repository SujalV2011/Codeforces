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
        int n;
        cin >> n;
        string s;
        cin >> s;

        ll ans = LLONG_MAX;
        for (char ch : {'a', 'b'})
        {
            vector<ll> pos;
            for (ll i = 0; i < n; i++)
                if (s[i] == ch)
                    pos.push_back(i);
            vector<ll> shifted;
            if (pos.empty() || pos.size() == n)
            {
                ans = 0;
                continue;
            }
            for (ll i = 0; i < (ll)pos.size(); i++)
                shifted.push_back(pos[i] - i);
            nth_element(shifted.begin(), shifted.begin() + shifted.size() / 2, shifted.end());
            ll cost = 0;
            ll median = shifted[shifted.size() / 2];
            for (ll x : shifted)
                cost += llabs(x - median);
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
}
