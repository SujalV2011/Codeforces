#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>b(n+2,0),pref(n+2,0);

        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            pref[i]=max(pref[i-1],b[i]);
            if(i%2==0)
                b[i]=max(pref[i],b[i]);
        }
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<b[i]<<" ";
        // }
        // cout<<endl;
        int ans=0;

        for(int i=(n%2?n:n-1);i>=1;i-=2)
        {
            if(i!=1 && b[i]>=b[i-1])
                ans+=(b[i]-b[i-1] + 1);
            
            if(i==1 && b[i]>=b[i+1])
                ans+=(b[i]-b[i+1] + 1);
        }

        cout<<ans<<endl;
    }
}