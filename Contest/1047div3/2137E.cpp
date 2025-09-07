#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Key {
    uint64_t a, b;
    bool operator==(const Key &o) const { return a == o.a && b == o.b; }
};

struct hash_key {
    size_t operator()(const Key &k) const {
        return (size_t)k.a ^ (size_t)k.b;
    }
};

Key get_hash(const vector<int>& v) {
    uint64_t h1 = 0, h2 = 0;
    const uint64_t p1 = 31, p2 = 37;
    for (int x : v) {
        h1 = h1 * p1 + (uint64_t)(x + 1);
        h2 = h2 * p2 + (uint64_t)(x + 1);
    }
    return {h1, h2};
}

vector<int> next_arr(const vector<int>& a) {
    int n = a.size();
    vector<int> freq(n + 3, 0);
    for (int x : a) {
        if (0 <= x && x < n + 3) freq[x]++;
    }
    int zero = 0;
    while (zero < n + 3 && freq[zero] > 0) zero++;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int v = a[i];
        if (0 <= v && v < n + 3 && freq[v] == 1 && v < zero) res[i] = v;
        else res[i] = zero;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> seq;
        seq.push_back(a);
        unordered_map<Key, int, hash_key> seen;
        seen[get_hash(a)] = 0;

        long long step = 0;
        vector<int> answer;
        while (true) {
            if (step >= k) {
                answer = seq[k];
                break;
            }
            vector<int> nx = next_arr(seq.back());
            step++;
            Key key = get_hash(nx);
            if (seen.count(key)) {
                int start = seen[key];
                seq.push_back(nx);
                int period = step - start;
                long long idx;
                if (k <= step) idx = k;
                else idx = start + (k - start) % period;
                answer = seq[idx];
                break;
            } else {
                seq.push_back(nx);
                seen[key] = (int)step;
            }
        }

        long long sum = 0;
        for (int x : answer) sum += x;
        cout << sum << "\n";
    }
    return 0;
}