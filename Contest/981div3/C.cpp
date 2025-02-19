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

const int N = 2e5 + 5;
vi a(N);


void perform_swaps(int n) 
{
    for (int i = 2; i <= n / 2; i++) 
    {
        if (a[i] == a[i - 1] || a[n - i + 1] == a[n - i + 2]) {
            swap(a[i], a[n - i + 1]);
        }
    }
}

int count_duplicates(int n) 
{
    int ans = 0;
    for (int i = 1; i < n; i++) 
    {
        if (a[i] == a[i + 1]) {
            ans++;
        }
    }
    return ans;
}

int main() {
    fastio();
    int t;
    cin >> t;

    while(t--) 
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) 
        {
            cin >> a[i];
        }        
        perform_swaps(n);          
        int ans = count_duplicates(n);

        cout << ans << endl;   
    }

    return 0;
}
