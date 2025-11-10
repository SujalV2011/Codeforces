#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll>arr(n+1,0),dp(n+1,0),pref(n+1,0);

    for(int i=1;i<=n;i++) cin>>arr[i];

    sort(arr.begin()+1,arr.end());
    pref[1]=arr[1];

    for(int i=2;i<=n;i++) pref[i]=pref[i-1]+arr[i];

    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+arr[i];
        // if(i>=k) cout<<pref[i]-pref[i-k]<<endl;
        // else cout<<pref[i]<<endl;
        if(i>=k+1)
            dp[i]=min(dp[i],dp[i-(k+1)]+pref[i]-pref[i-k]);
    }

    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    cout<<endl;
}
