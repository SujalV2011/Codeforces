#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        
        long long max_h = *max_element(h.begin(), h.end());
        if (h[k-1] == max_h) {
            cout << "YES\n";
            continue;
        }
        
        vector<long long> unique_h = h;
        sort(unique_h.begin(), unique_h.end());
        unique_h.erase(unique(unique_h.begin(), unique_h.end()), unique_h.end());
        
        long long s = h[k-1];
        long long curr = s;
        bool can_reach = false;
        
        for (long long height : unique_h) 
        {
            if (height <= curr) continue;
            if (height - curr <= s) 
            {
                curr = height;
                if (height == max_h) 
                {
                    can_reach = true;
                    break;
                }
            } 
            else 
            {
                break;
            }
        }
        
        cout << (can_reach ? "YES\n" : "NO\n");
    }
    
    return 0;
}