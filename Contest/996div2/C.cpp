// This program is made by Sujal Vekariya
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

void initializeMatrix(ll n, ll m, vector<vector<ll>> &a, vector<ll> &rr, vector<ll> &cl) {
    for (ll i = 1; i <= n; i++) 
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            rr[i] += a[i][j];
            cl[j] += a[i][j];
        }
    }
}

void processMoves(const string &s, ll n, ll m, vector<vector<ll>> &a, vector<ll> &rr, vector<ll> &cl) {
    ll l = 1, r = 1;
    for (char move : s) {
        if (move == 'D') {
            ll tmp = -rr[l];
            a[l][r] = tmp;
            rr[l] = tmp + a[l][r];
            cl[r] += tmp;
            l++;
        } else {
            ll tmp = -cl[r];
            a[l][r] = tmp;
            cl[r] = tmp + a[l][r];
            rr[l] += tmp;
            r++;
        }
    }
    a[n][m] = -cl[m];
}

void printMatrix(ll n, ll m, const vector<vector<ll>> &a) {
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fastio();

    ll t;
    cin >> t;

    while (t--) 
    {
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
        vector<ll> rr(n + 1, 0), cl(m + 1, 0);

        initializeMatrix(n, m, a, rr, cl);
        processMoves(s, n, m, a, rr, cl);
        printMatrix(n, m, a);
    }

    return 0;
}
