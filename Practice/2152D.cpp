#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> a(n+1),cnt(n+1),sum(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+__lg(a[i])+(__builtin_popcount(a[i])>=2);
            cnt[i]=cnt[i-1]+(__builtin_popcount(a[i])==2 and a[i]&1);
        }
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin>>l>>r;
            cout<<sum[r]-sum[l-1]-(cnt[r]-cnt[l-1]+1)/2<<endl;
        }
    }
	return 0;
}
