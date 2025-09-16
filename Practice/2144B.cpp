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
        vector<int>arr(n);
        vector<bool>vis(n+1,false);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            vis[arr[i]]=true;
        }

        int start=n;

        for(int i=n;i>=1;i--)
        {
            if(!vis[i])
            {
                start=i;
                break;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                arr[i]=start;
                vis[start]=true;
                while(start>0 && vis[start]) start--;
            }
        }

        
        int i=0;

        while(i<n && arr[i]==i+1)
        {
            i++;
        }
        int j=n-1;

        while(j>=0 && arr[j]==j+1)
        {
            j--;
        }
        if(i>j) cout<<0<<endl;
        else
            cout<<j-i+1<<endl;
        
    }
}