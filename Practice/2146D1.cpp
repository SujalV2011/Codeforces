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

        for(int k=pow_log2(r);k>l;k/=2)
        {
            if(used[pos[k]])    continue;
            for(int i=pos[k],j=pos[k]-1;i<=r && j>=0;i++,j--)
            {
                if(used[i]) break;
                swap(pos[ans[i]],pos[ans[j]]);
                swap(ans[i],ans[j]);
                used[i]=used[j]=true;
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