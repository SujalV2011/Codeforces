#include <bits/stdc++.h>
using namespace std;
 

unsigned int computeOR(unsigned int k){
    if(k == 0) return 0;
    unsigned int r = 0;
    while((1u << r) <= (k - 1)) r++;
    return (1u << r) - 1;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        unsigned int x;
        cin >> n >> x;
 
       
        int m0 = 0;
        for (int y = 0; y <= n; y++){
            if ((y & (~x)) != 0) {
                m0 = y;
                break;
            }
        }
        if(m0 == 0) {
            m0 = n + 1;
        }
 
        int k;
        if(m0 < n){
            k = m0;
        } else {
            if(computeOR(n) == x) k = n;
            else k = n - 1;
        }
 
        vector<unsigned int> ans;
        ans.reserve(n);
        for (int i = 0; i < k; i++){
            ans.push_back(i);
        }
 
        unsigned int currentOR = 0;
        for (int i = 0; i < k; i++){
            currentOR |= ans[i];
        }
 
        if(n > k){
            if(currentOR != x){
                ans.push_back(x);
                currentOR |= x;
            }
            
            while(ans.size() < (size_t)n){
                ans.push_back(0);
            }
        }
 
        for (int i = 0; i < n; i++){
            cout << ans[i] << (i + 1 < n ? " " : "\n");
        }
    }
    return 0;
}