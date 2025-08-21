#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
	// your code goes here
    int t=0;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>arr(n);
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        
        ll ans=0;
        
        for(int i=1;i<=60;i++)
        {
            set<ll>st;
            ll k=1LL<<i;
            
            for(int j=0;j<n;j++)
            {
                st.insert(arr[j]%k);
            }
            
            if(st.size()==2)
            {
                ans=k;
                break;
            }
        }
        
        cout<<ans<<endl;
    }
}
