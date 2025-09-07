#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
             
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) 
        {
            ans[i]=n+1-arr[i];
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
