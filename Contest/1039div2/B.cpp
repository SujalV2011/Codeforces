#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> P(N);
        for (int &x : P) cin >> x;
        string ans;
        int l = 0, r = N-1;
        for (int turn = 1; turn <= N; ++turn) {
            bool takeLeft;
            if (turn % 2 == 1) // on odd turns
                takeLeft = P[l] < P[r]; // take minimum
            else // on even turns
                takeLeft = P[l] > P[r]; // take maximum
            if (takeLeft) {
                ans.push_back('L');
                ++l;
            } else {
                ans.push_back('R');
                --r;
            }
        }
        cout << ans << '\n';
    }
}