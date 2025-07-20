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

struct Casino {
    ll l, r, real;
};

struct SegmentTree {
    vector<vll> tree;
    int n;

    SegmentTree(int sz) {
        n = sz;
        tree.resize(4 * sz);
    }

    void update(int node, int start, int end, int l, int r, int idx) {
        if (r < start || l > end) return;
        if (l <= start && end <= r) {
            tree[node].pb(idx);
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, l, r, idx);
        update(2 * node + 2, mid + 1, end, l, r, idx);
    }

    vll query(int node, int start, int end, int pos) {
        vll result = tree[node];
        if (start == end) {
            tree[node].clear(); // Clear only the queried leaf node
            return result;
        }
        int mid = (start + end) / 2;
        if (pos <= mid) {
            auto left = query(2 * node + 1, start, mid, pos);
            result.insert(result.end(), all(left));
        } else {
            auto right = query(2 * node + 2, mid + 1, end, pos);
            result.insert(result.end(), all(right));
        }
        tree[node].clear(); // Clear the current node's list after query
        return result;
    }
};

int main() {
    fastio();

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<Casino> casinos(n);
        vll values = {k};
        for (int i = 0; i < n; i++) {
            cin >> casinos[i].l >> casinos[i].r >> casinos[i].real;
            values.pb(casinos[i].l);
            values.pb(casinos[i].r);
            values.pb(casinos[i].real);
        }

        sort(all(values));
        values.erase(unique(all(values)), values.end());
        int m = sz(values);

        auto get_index = [&](ll x) {
            return lower_bound(all(values), x) - values.begin();
        };

        SegmentTree st(m);
        for (int i = 0; i < n; i++) {
            int l_idx = get_index(casinos[i].l);
            int r_idx = get_index(casinos[i].r);
            st.update(0, 0, m - 1, l_idx, r_idx, i);
        }

        queue<int> q;
        vector<bool> visited(m, false);
        vll max_coins(m, -1);
        int start_idx = get_index(k);
        q.push(start_idx);
        visited[start_idx] = true;
        max_coins[start_idx] = k;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            vll casino_indices = st.query(0, 0, m - 1, curr);

            trav(idx, casino_indices) {
                int next_idx = get_index(casinos[idx].real);
                if (!visited[next_idx]) {
                    visited[next_idx] = true;
                    max_coins[next_idx] = casinos[idx].real;
                    q.push(next_idx);
                } else {
                    max_coins[next_idx] = max(max_coins[next_idx], casinos[idx].real);
                }
            }
        }

        ll ans = *max_element(all(max_coins));
        cout << ans << '\n';
    }

    return 0;
}