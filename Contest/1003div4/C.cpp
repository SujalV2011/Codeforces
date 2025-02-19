#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m, B;
        cin >> n >> m;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        cin >> B;

        if (n == 1) {
            cout << "YES\n";
            continue;
        }

        bool dp0 = true, dp1 = true;
        for (int i = 1; i < n; i++) {
            bool new0 = (dp0 && a[i - 1] <= a[i]) || (dp1 && B - a[i - 1] <= a[i]);
            bool new1 = (dp0 && a[i - 1] <= B - a[i]) || (dp1 && B - a[i - 1] <= B - a[i]);
            dp0 = new0;
            dp1 = new1;
        }

        cout << (dp0 || dp1 ? "YES\n" : "NO\n");
    }
    
    return 0;
}