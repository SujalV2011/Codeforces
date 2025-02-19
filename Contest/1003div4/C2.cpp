#include <bits/stdc++.h>
using namespace std;

const long long INF = INT_MAX;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(b.begin(), b.end());

    long long prev = INT_MIN;
    for (int i = 0; i < n; i++) {
        long long option1 = (a[i] >= prev) ? a[i] : INF;
        auto it = lower_bound(b.begin(), b.end(), prev + a[i]);
        long long option2 = (it != b.end()) ? (*it - a[i]) : INF;

        prev = min(option1, option2);
        if (prev == INF) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}