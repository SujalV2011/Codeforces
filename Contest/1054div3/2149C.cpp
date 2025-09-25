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
        vector<int>a(n);
        map<int,bool>mp;

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==k) cnt++;
            mp[a[i]]=true;
        }
        int nt=0;
        for(int i=0;i<k;i++)
        {
            if(!mp[i])
                nt++;
        }
        cout<<max(nt,cnt)<<endl;
    }
}