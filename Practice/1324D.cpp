#include<bits/stdc++.h>
using namespace std;
using ll=long long;

/*
    Observations:

       here we need to find pairs with condition ai+aj>bi+bj
       so we will first make pirs of ai and bi
       then we will them up with their difference like theire diff then pair ai,bi
       then we will sort them in ascending order according to their difference
       then we will do binary search for each pair the lowest index j>i such that ai+aj>bi+bj
       then we will add n-j to the answer as all the pairs after j will also satisfy the condition
*/

int main()
{
    
    int n;
    cin>>n;
    vector<pair<ll,pair<ll,ll>>>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i].second.first;
    for(int i=0;i<n;i++)
        cin>>v[i].second.second;

    for(int i=0;i<n;i++)
        v[i].first=v[i].second.first-v[i].second.second;

    sort(v.begin(),v.end());
    int l=0,hi=n-1,mid=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        l=i+1,hi=n-1;
        while(l<=hi)
        {
            mid=l+(hi-l)/2;
            if(v[i].first+v[mid].first>0)
                hi=mid-1;
            else
                l=mid+1;
        }
        ans+=n-l;
    }

    cout<<ans<<endl;
        
}