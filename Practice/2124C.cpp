#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long & x : a) cin >> x;

        long long gcd = 0;
        long long lcm = 1;

        for (int i = n - 1; i >= 0; --i) {
            gcd = gcd == 0 ? a[i] : std::gcd(gcd, a[i]);
            lcm = std::lcm(lcm,  a[i] / gcd);
        }

        cout << lcm << '\n';
    }

    return 0;
}