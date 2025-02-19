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
#define trav(x, v) for (auto &x : v)
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

ll countPairs(const vll &arr, ll sum, ll x, ll y) 
{
    ll maxsum = sum - x;
    ll cnt = 0;
    ll minsum = sum - y;

    for(int i = 0; i < arr.size(); i++) 
    {
        ll reqMin = minsum - arr[i];
        ll reqMax = maxsum - arr[i];
        auto l = lower_bound(arr.begin() + i + 1, arr.end(), reqMin);
        auto r = upper_bound(arr.begin() + i + 1, arr.end(), reqMax);
        cnt += distance(l, r);
    }

    return cnt;
}

int main() {
    fastio();
    
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        ll x, y;
        cin >> n >> x >> y;

        vll arr(n);
        ll sum = 0;

        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
            sum += arr[i];
        }

        sort(all(arr));
        cout << countPairs(arr, sum, x, y) << endl;
    }

    return 0;
}
