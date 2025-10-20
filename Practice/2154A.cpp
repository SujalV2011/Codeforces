#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int l=-n,ans=0;

        for(int i=0;i<n;i++)
        {
            char ch;
            cin>>ch;

            if(ch=='1')
            {
                if(i-l>=k)
                {
                    ans++;
                }
                l=i;
            }
        }
        cout<<ans<<endl;
    }
}