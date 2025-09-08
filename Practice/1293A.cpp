#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s,k;
        cin>>n>>s>>k;

        set<ll>st;
        for(int i=0;i<k;i++)
        {
            ll x;
            cin>>x;
            st.insert(x);
        }
        st.insert(0);

        if(st.find(s)==st.end())
        {
            cout<<0<<endl;
            continue;
        }
        int i=s-1;
        int idx=-1;
        ll ans=LLONG_MAX;
        while(i>1 and st.find(i)!=st.end())
        {
            i--;
        }
        if(st.find(i)==st.end())
        {
            idx=i;
        }
        i=1;
        
        while(s+i<=n && st.find(s+i)!=st.end())
        {
            i++;
        }
        // cout<<idx<<endl;
        // cout<<i<<endl;
        int idx2=-1;
        if(s+i<=n)
        {
            idx2=i;
        }

        if(idx2==-1)
        {
            ans=abs(s-idx);
        }
        else if(idx!=-1 && s-idx<=idx2)
        {
            ans=s-idx;
        }
        else
        {
            ans=idx2;
        }
        cout<<ans<<endl;
    }
}