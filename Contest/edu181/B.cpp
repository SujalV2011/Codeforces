#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,k;
        cin>>a>>b>>k;

        ll mn =min(a,b);

        if(k>=max(a,b))
        {
            cout<<1<<endl;
            continue;
        }
        
        ll gcd=__gcd(a,b);

        if(a/gcd<=k && b/gcd<=k)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<2<<endl;
        }

    }
}