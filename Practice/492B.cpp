#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,l;
    cin>>n>>l;

    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    sort(v.begin(),v.end());

    double ans=(v[0]-0.0)*1.0;

    for(int i=0;i<n-1;i++)
    {
        ans=max(ans,(v[i+1]-v[i])/2.0);
    }
    ans=max(ans,(l-v[n-1])*1.0);

    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}