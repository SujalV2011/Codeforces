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
    while (t--) 
    {
        int k;
        cin >> k;
        vector<int> values(k);
        unordered_map<int, int> freq;

        for (int i = 0; i < k; i++) 
        {
            cin >> values[i];
            freq[values[i]]++;
        }

        bool found = false;
        pair<int, int> result;

        for (int n = 1; n * n <= k - 2; n++) 
        {
            if ((k - 2) % n == 0) 
            {
                int m = (k - 2) / n;
                if (freq[n] > 0 && freq[m] > 0) 
                {
                    result = {n, m};
                    found = true;
                    break;
                }
            }
        }

        if (found) 
        {
            cout << result.first << " " << result.second << endl;
        } 
        else 
        {
            cout << 1 << " " << k - 1 << endl;
        }
    }
    return 0;
}