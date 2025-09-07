#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        unordered_map<ll, vector<int>> groups;
        for (int i = 0; i < n; i++) 
        {
            groups[b[i]].push_back(i);
        }

        vector<ll> a(n, 0);
        ll label = 1;
        bool ok = true;

        for (auto &p : groups) 
        {
            ll x = p.first;
            auto &idx = p.second;

            if ((int)idx.size() % x != 0)
            {
                ok = false;
                break;
            }

            for (int i = 0; i < (int)idx.size(); i++) 
            {
                a[idx[i]] = label;
                if ((i + 1) % x == 0) label++;
            }
        }

        if (!ok) 
        {
            cout << -1 << "\n";
        } 
        else 
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
