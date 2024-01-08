#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,n,cnt=1;
        cin>>x>>y>>n;
        int a[n];
        a[n-1]=y;
        a[0]=x;
        for(int i=n-2;i>=1;i--)
        {
            a[i]=a[i+1]-cnt;
            cnt++;
        }
        if((a[1]-a[0])>(a[2]-a[1]))
        {
            for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        }
        else
            cout<<-1;
        cout<<endl;    
    }
    return 0;
}