#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(),a.end());

        if(m>=n)
        {
            ll sum=0;
            int ops=m;
            
            for(int i=n-1;i>0;i--)
            {
                sum+=(ops*a[i]);
                ops--;
            }
            sum+=(ops*a[0]); 
            cout<<sum<<endl;          
        }
        else
        {
            ll sum=0;
            int idx=n-1;
            while(m>0)
            {
                sum+=(m*a[idx]);
                idx--;
                m--;
            }

            cout<<sum<<endl;
        }
    }
}
