#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> ans;
        __int128 pow10 = 10;
        for (int k = 1; k <= 18; ++k) 
        {
            long long s = (long long)(1 + pow10); 
            if (s > n) break;
            if (n % s == 0) 
            {
                ans.push_back(n / s);
            }
            pow10 *= 10;
        }
        if (ans.empty()) 
        {
            cout << 0 << '\n';
        } 
        else 
        {
            sort(ans.begin(), ans.end());
            cout << ans.size()<< '\n';
            for (long long x : ans) cout << " " << x;
            cout << '\n';
        }
    }
    return 0;
}
