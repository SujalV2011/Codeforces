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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    if (a == 0 || b == 0) return 0;
    ll g = gcd(a, b);
    if (a > (1LL << 62) / (b / g)) return -1; // Check for overflow
    return (a / g) * b;
}

bool is_prime(ll n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main()
{
    fastio();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vll p(n), s(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> s[i];

        vll a(n);
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            ll g = gcd(p[i], s[i]);
            if (p[i] % g != 0 || s[i] % g != 0)
            {
                possible = false;
                break;
            }
            ll lcm_val = lcm(p[i], s[i]);
            if (lcm_val == -1 || lcm_val > 1e18)
            {
                possible = false;
                break;
            }
            a[i] = lcm_val;
        }

        if (possible)
        {
            vll pre(n), suf(n);
            pre[0] = a[0];
            for (int i = 1; i < n; i++) pre[i] = gcd(pre[i-1], a[i]);
            suf[n-1] = a[n-1];
            for (int i = n-2; i >= 0; i--) suf[i] = gcd(a[i], suf[i+1]);

            for (int i = 0; i < n; i++)
            {
                if (pre[i] != p[i] || suf[i] != s[i])
                {
                    possible = false;
                    break;
                }
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}