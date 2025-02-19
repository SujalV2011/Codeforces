#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define pb push_back
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

bool mark2[N], mark[N];
int cnt, cnt2, n, m1, m2, col[N];
vi adj1[N], adj2[N];
map<pii, int> mp;

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

void dfs2(int u) {
    col[u] = cnt;
    mark2[u] = true;
    for (int v : adj2[u]) {
        if (!mark2[v]) {
            dfs2(v);
        }
    }
}

void dfs(int u) {
    mark[u] = true;
    for (int v : adj1[u]) {
        if (!mark[v] && mp[{u, v}] != 1) {
            dfs(v);
        }
    }
}

int main() {
    fastio();

    auto processGraphInput = [&](int m1, int m2) {
        for (int i = 0; i < m1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for (int i = 0; i < m2; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
    };

    auto performDFS = [&]() {
        for (int i = 0; i < n; i++) {
            if (!mark2[i]) {
                cnt++;
                dfs2(i);
            }
        }
    };

    auto calculateAnswer = [&]() {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int v : adj1[i]) {
                if (col[i] != col[v]) {
                    ans++;
                    mp[{i, v}] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!mark[i]) {
                cnt2++;
                dfs(i);
            }
        }

        return ans / 2 + (cnt2 - cnt);
    };

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m1 >> m2;
        cnt = 0, cnt2 = 0;
        mp.clear();

        for (int i = 0; i < n; i++) {
            adj1[i].clear();
            adj2[i].clear();
            mark[i] = false;
            mark2[i] = false;
        }

        processGraphInput(m1, m2);
        performDFS();

        int ans = calculateAnswer();

        cout << ans << endl;
    }

    return 0;
}
