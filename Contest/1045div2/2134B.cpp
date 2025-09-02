#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modpow(ll a, ll b, ll m) 
{
    ll res = 1;
    while (b) 
    {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll smallestPrimeFactor(ll x) 
{
    if (x % 2 == 0) return 2;
    for (ll i = 3; i * i <= x; i += 2) 
    {
        if (x % i == 0) return i;
    }
    return x;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n; ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        ll p = smallestPrimeFactor(k + 1);
        ll inv = modpow(k % p, p - 2, p);

        for (int i = 0; i < n; i++) 
        {
            ll s = (p - (a[i] % p)) % p;
            s = s * inv % p;
            a[i] += s * k;
        }
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}
