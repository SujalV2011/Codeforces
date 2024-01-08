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
        int a[n],maxnum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
                maxnum=max(a[i],maxnum);
        }
        cout<<maxnum<<endl;
    }
    return 0;
}