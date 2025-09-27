#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n*(n-1)/2);

        for(int i=0;i<n*(n-1)/2;i++)
        {
            cin>>a[i];
        }

        sort(a.begin(),a.end());

        int inc=n-1;
        int i=0;
        while(inc>0 && i<n*(n-1)/2)
        {
            cout<<a[i]<<" ";
            i+=inc;
            // cout<<i<<endl;
            inc-=1;
            // cout<<inc<<endl;
        }
        cout<<a[n*(n-1)/2 - 1];
        cout<<endl;
    }
}