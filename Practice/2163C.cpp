#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>arr(2,vector<int>(n,0));

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }

        vector<int>prefmn(n+1,0),prefmx(n+1,0);
        prefmn[0]=arr[0][0];
        prefmx[0]=arr[0][0];
        for(int i=1;i<n;i++)
        {
            prefmn[i]=min(prefmn[i-1],arr[0][i]);
            prefmx[i]=max(prefmx[i-1],arr[0][i]);
        }

        vector<int>suffmx(n+1,0),suffmn(n+1,0);
        suffmn[n-1]=arr[1][n-1];
        suffmx[n-1]=arr[1][n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffmn[i]=min(suffmn[i+1],arr[1][i]);
            suffmx[i]=max(suffmx[i+1],arr[1][i]);
        }

        // int minmax=1,maxmin=2*n;
        vector<int> ans(2*n+1,2*n+1);

        for(int i=0;i<n;i++)
        {
            int x=min(prefmn[i], suffmn[i]);
            int y=max(prefmx[i], suffmx[i]);
            ans[x]=min(ans[x],y);
        }
        // for(int i=1;i<=2*n;i++)
        // {
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;

        int res=0;
        for(int i=2*n;i>=1;i--)
        {
            if(i<2*n)
                ans[i]=min(ans[i],ans[i+1]);
            if(ans[i]<=2*n)
                res+=(2*n - ans[i] + 1);
        }
        cout<<res<<endl;
    } 
    return 0;
}