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

tuple<int, int, int> find_answer(int l, int r) 
{
    int idx, ans = 0;
    for (int i = 29; i >= 0; i--) 
    {
        if ((r & (1 << i)) != (l & (1 << i))) 
        {
            ans += (1 << i);
            idx = i;
            break;
        } 
        else 
        {
            if ((l & (1 << i))) 
            {
                ans += (1 << i);
            }
        }
    }

    return {ans, ans - 1, (ans == r) ? r - 2 : r};
}

int main() {
    fastio();
    int t;
    cin >> t;

    while (t--) 
    {
        int l, r;
        cin >> l >> r;
        
        tuple<int, int, int> result = find_answer(l, r);
        int first = get<0>(result);
        int second = get<1>(result);
        int third = get<2>(result);
        
        cout << first << " " << second << " " << third << endl;
    }

    return 0;
}
