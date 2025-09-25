#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);

        for(int i=0;i<n;i++)    cin>>a[i];
        for(int i=0;i<n;i++)    cin>>b[i];

        int ans=1;

        for(int i=0;i<n;i++)
        {
            if(a[i] > b[i]) 
                swap(a[i], b[i]);
            if(!i || a[i] >= b[i - 1]) 
                ans = (ans * 2LL) % mod;
        }

        cout<<ans<<endl;
    }
    return 0;
}