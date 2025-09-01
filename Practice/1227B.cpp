#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);

        for(int i=0;i<n;i++) cin>>a[i];
        vector<int>ans(n,0);
        vector<int>vis(n+1,0);
        ans[0]=a[0];
        vis[a[0]]=-1;
        bool flg=false;
        for(int i=1,j=1;i<n;i++)
        {
            if(a[i]>a[i-1])
            {
                ans[i]=a[i];
                vis[a[i]]=-1;
            }
            else if(a[i]<a[i-1])
            {
                flg=true;
                break;
            }
            else if(a[i]==a[i-1])
            {
                while(vis[j]!=0) j++;
                if(j>=a[i])
                {
                    flg=true;
                    break;
                }
                ans[i]=j;
                vis[j]=-1;
            }
        }

        if(flg) cout<<-1<<endl;
        else
        {
            for(int i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }

    }
}