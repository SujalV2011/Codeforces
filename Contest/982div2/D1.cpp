// This program is made by sujal Vekariya
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define trav(x, v) for(auto &x : v)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
#define desync() cout.flush(), system("pause"), _Exit(0)

vll pre_sum(const vll &a) 
{
    int n = a.size();
    vll pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }
    return pre;
}

ll min_ops(int n, int m, const vll &a, const vll &b, const vll &pre) 
{
    vll dp(n + 1, 1e18);
    dp[0] = 0;

    for (int k = 1; k <= m; k++) 
    {
        ll out = b[k - 1];
        for (int i = 0; i < n; i++) 
        {
            if (dp[i] == 1e18)
            {
                continue;
            } 
            ll x = pre[i] + out;
            ll y = upper_bound(all(pre), x) - pre.begin();
            ll j = y - 1;

            if (j >= i + 1 && j <= n) 
            {
                dp[j] = min(dp[j], dp[i] + (ll)(m - k));
            }
        }
    }
    return dp[n];
}

int main() 
{
    fastio();
    int t;
    cin >> t;

    while(t--) 
    {
        int n, m;
        cin >> n >> m;

        vll a(n);
        for (auto &x : a) cin >> x;

        vll b(m);
        for (auto &x : b) cin >> x;

        vll pre = pre_sum(a);
        ll result = min_ops(n, m, a, b, pre);

        if (result == 1e18) 
        {
            cout << -1 << endl;
        } 
        else 
        {
            cout << result << endl;
        }
    }
    return 0;
}
