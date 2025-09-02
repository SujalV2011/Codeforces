#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;

        ll x=n-a+1;
        ll y=n-b+1;

        if(b>a && n%2==0 && b%2==0)
        {
            cout<<"YES"<<endl;
        }
        else if (b>a && n%2==1 && b%2==1)
        {
            cout<<"YES"<<endl;
        }
        else if(a==b and a==n)
        {
            cout<<"YES"<<endl;
        }
        else if(n%2==0 and a%2==0 and b%2==0)
        {
            cout<<"YES"<<endl;
        }
        else if(n%2==1 and a%2==1 and b%2==1)
        {
            cout<<"YES"<<endl;
        }
        else 
        {
            cout<<"NO"<<endl;
        }
        
    }
}