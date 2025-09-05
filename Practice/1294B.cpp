#include<bits/stdc++.h>
using namespace std;
using ll=long long;

static bool cmp(pair<ll,ll> &a,pair<ll,ll> &b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first;
            cin>>a[i].second;
        }

        sort(a.begin(),a.end(),cmp);

        string ans="";

        ll x=0;
        ll y=0;
        for(int i=0;i<n;i++)
        {
            // cout<<"x= "<<a[i].first<<" y="<<a[i].second<<endl;
            if(a[i].first>=x && a[i].second>=y)
            {
                while(x<a[i].first && y<=a[i].second)
                {
                    ans+='R';
                    x++;
                }
                while(y<a[i].second && x<=a[i].first)
                {
                    ans+='U';
                    y++;
                }
            }
            else
            {
                ans="NO";
                break;
            }
        }
        if(ans=="NO")
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
    }
}