//This program is made by sujal Vekariya
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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n, m, L;
        cin >> n >> m >> L;
        vector<pii> hurdles(n), pwr(m);
        for (int i = 0; i < n; ++i) cin >> hurdles[i].first >> hurdles[i].second;
        for (int i = 0; i < m; ++i) cin >> pwr[i].first >> pwr[i].second;
        
        sort(all(hurdles));
        sort(all(pwr));
        int j = 0, pu = 0, res = 0, pwr_idx = 0;
        ll pos = 1, k = 1;
        
        while (pos < L) {
            ll nxt = pos + k;
            while (j < n && hurdles[j].first <= nxt) {
                nxt = min(nxt, (ll)hurdles[j].first - 1);
                ++j;
            }
            while (pwr_idx < m && pwr[pwr_idx].first <= pos) {
                pu += pwr[pwr_idx].second;
                ++pwr_idx;
            }
            if (nxt >= L) break;
            if (nxt <= pos) {
                if (!pu) { cout << -1 << '\n'; break; }
                k += pu;
                pu = 0;
                ++res;
            }
            pos = nxt;
        }
        if (pos >= L) cout << res << '\n';
    }
    
    return 0;
}