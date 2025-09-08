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
        vector<ll>arr(n);
        for(int i=0;i<n;i++)    cin>>arr[i];

        vector<ll>suff(n+1,0);
        suff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=min(suff[i+1],arr[i]);
        }

        ll cnt=0;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>suff[i+1])
            {
                cnt++;
            }
        }

        cout<<cnt<<endl;
    }
}