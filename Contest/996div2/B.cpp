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

int main() {
    fastio();
    
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        vll a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < n; j++) cin >> b[j];

        int ind = 0;
        ll lg = 0;

        for (int i = 0; i < n; i++) 
        {
            if (a[i] < b[i] && abs(a[i] - b[i]) >= lg) 
            {
                lg = abs(a[i] - b[i]);
                ind = i;
            }
        }

        bool flag = false;

        for (int i = 0; i < n; i++) 
        {
            if (i != ind && a[i] - lg < b[i]) 
            {
                flag = true;
                break;
            }
        }

        if (flag) 
        {
            cout << "NO"<<endl;
        } 
        else 
        {
            cout << "YES"<<endl;
        }
    }

    return 0;
}
