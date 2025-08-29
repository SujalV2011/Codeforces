#include"bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        ll cnt=(k-1)/(n-1);
        k+=cnt;
        cout<<k<<endl;
    }
}