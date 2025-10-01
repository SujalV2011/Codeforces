#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,j=1;
        cin>>n;
        vector<int> f(n+1),a(n+1),freq(n+1,0),p(n+1);
        for(int i=1;i<=n;i++) cin>>f[i];

        while(j<=f[1]-n) a[j++]=1;
        for(int i=2;i<=n;i++)
        {
            int limit = j+f[i];
            while(j<limit && j<=n) a[j++]=i;
        }
        
        a[n]=1;
        
        p[1]=a[1];
        for(int i=2;i<=n;i++) p[i]=max(p[i-1],a[i]);
        
        for(int i=1;i<=n;i++) freq[p[i]]++;
        freq[1]+=n;
        
        bool possible=true;
        for(int i=1;i<=n;i++)
        {
            if(freq[i]!=f[i])
            {
                possible=false;
                break;
            }
        }
        
        if(possible)
        {
            for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        }
        else cout<<-1;
        cout<<endl;
        
    }

    return 0;
}