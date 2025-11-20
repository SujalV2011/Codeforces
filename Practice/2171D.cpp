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
        int a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<int>pref(n),suff(n);
        pref[0]=a[0];
        for(int i=1;i<n;i++)
            pref[i]=min(pref[i-1],a[i]);
        suff[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
            suff[i]=max(suff[i+1],a[i]);

        bool flag=true;

        for(int i=0;i<n-1;i++)
        {
            if(pref[i]>suff[i+1])
            {
                flag=false;
                break;
            }
        }

        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}