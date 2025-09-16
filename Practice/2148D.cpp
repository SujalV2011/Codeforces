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
        vector<ll>a(n);

        for(int i=0;i<n;i++)    cin>>a[i];

        bool ok=false;
        ll sum=0;
        vector<ll>odd;
        for(int i=0;i<n;i++)
        {
            if(a[i]&1)
            {
                odd.push_back(a[i]);
                ok=true;
            }
            else
            {
                sum+=a[i];
            }
        }

        if(!ok)
        {
            cout<<0<<endl;
            continue;
        }

        sort(odd.rbegin(),odd.rend());
        for(int i=0;i<(odd.size()+1)/2;i++)
        {
            sum+=odd[i];
        }
        cout<<sum<<endl;

    }
}