#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    vector<ll>dp(2*1e5+1,-1);
    ll cnt=0;
    for(int i=1;i<=2*1e5;i++)
    {
        cnt=0;
        int j=i;
        while(j>0)
        {
            j/=3;
            cnt++;
            if(dp[j]!=-1)
            {
                cnt+=dp[j];
                break;
            }
        }
        dp[i]=cnt;
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        ll ans=0;
        ans+=(2*dp[l]);

        for(int i=l+1;i<=r;i++) ans+=dp[i];

        cout<<ans<<endl;
    }
}