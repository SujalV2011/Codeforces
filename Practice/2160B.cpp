#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<ll>b(n);

        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        vector<ll>a(n);
        iota(a.begin(),a.end(),1LL);

        for(int i=1;i<n;i++)
        {
            if(b[i]-b[i-1]<=i)
            {
                a[i]=a[i-(b[i]-b[i-1])];
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}