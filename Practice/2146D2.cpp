#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int pow_log2(int x)
{
    return 1 << (31 - __builtin_clz(x));
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;

        vector<int>ans(r-l+1);
        map<int,int>pos;

        for(int i=l,p=0;i<=r;i++,p++)
        {
            ans[p]=i;
            pos[i]=p;
        }

        vector<bool>used(r-l+1,false);

        for(int k=2*pow_log2(r);k>=1;k/=2)
        {
            for(int i=r;i>=l;i--)
            {
                if(used[pos[i]])    continue;
                int x=k-1;
                int comp=x^i;
                if(comp<l || comp>r || used[pos[comp]]) continue;
                used[pos[i]]=used[pos[comp]]=true;
                swap(pos[i],pos[comp]);
                swap(ans[pos[i]],ans[pos[comp]]);
            }
        }

        ll sum=0;

        for(int i=l,j=0;i<=r;i++,j++)
        {
            sum+=(ans[j] | i);
        }

        cout<<sum<<endl;
        for(int i=0;i<r-l+1;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}