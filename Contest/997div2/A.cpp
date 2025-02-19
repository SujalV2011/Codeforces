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

int main() {
    fastio();

    int t;
    cin >> t;
    int n, m;
    while (t--) 
    {
        
        cin >> n >> m;

        vector<int> start(2, 0);
        vector<int> starf(2, 0);
        bool flag = false;

        for (int i = 0; i < n; i++) 
        {
            vector<int> L(2);
            cin >> L[0] >> L[1];
            start[1] += L[1];
            start[0] += L[0];

            if (!flag) 
            {
                starf[1] = start[1];
                starf[0] = start[0];
                flag = true;
            }
        }

        start[0] += m;
        start[1] += m;

        cout << 2 * (start[0] - starf[0]) + 2 * (start[1] - starf[1]) << endl;
    }

    return 0;
}
