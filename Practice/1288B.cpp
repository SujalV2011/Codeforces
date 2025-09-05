#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll cnt=0;
        ll x=9;
        while(x<=b)
        {
            cnt++;
            x=x*10+9;
        }

        cout<<cnt*a<<endl;
    }
}