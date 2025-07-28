#include <bits/stdc++.h>
using namespace std;

int computeDeadline(int64_t a, int64_t c) {
    int k = 0;
    while (a <= c) {
        a *= 2;
        k++;
    }
    return k;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int64_t c;
        cin >> n >> c;

        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector<int> deadlines;
        for (int i = 0; i < n; ++i) {
            deadlines.push_back(computeDeadline(a[i], c));
        }

        sort(deadlines.begin(), deadlines.end());

        int freeCount = 0;
        int coins = 0;

        for (int d : deadlines) {
            if (freeCount < d) {
                freeCount++;
            } else {
                coins++;
            }
        }

        cout << coins << '\n';
    }
    return 0;
}