#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;

        map<pair<int,int>,int>mp;
        vector<int>a(n);

        for(int i=0;i<n;i++)    cin>>a[i];
        int ans=0;

        for(int i=0;i<n;i++)
        {
            pair<int,int> p={(x - a[i]%x)%x, a[i]%y};
        
            // cout<<"required x for a : "<<(x-a[i]%x)%x<<" remainder of a: "<<a[i]%y<<endl;
            // cout<<"a: "<<a[i]<<endl;
            // cout<<"a[i] + a[j]: "<<mp[{(x-a[i]%x)%x,a[i]%y}]<<endl;
            ans+=(mp[p]);
            
            mp[{a[i]%x,a[i]%y}]++;
            
        }
        cout<<ans<<endl;
    }
}
