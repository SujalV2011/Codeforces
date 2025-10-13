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
        string s;
		cin>>s;
		map<int,int>mp;
		int ca=0,cb=0;
		s="*"+s;
		for(int i=1;i<=n;i++)
        {
			if(s[i]=='a')   ca++;
			else    cb++;
		}

		mp.clear();
		int diff=ca-cb,ans=n;

		if(diff==0)
        {
			cout<<0<<endl;
			continue;
		}

		for(int i=-2*n;i<=2*n;i++)
            mp[i]=-1;

		mp[0]=0;
		int sum=0;

		for(int i=1;i<=n;i++)
        {
			sum+=(s[i]=='a'?1:-1);
			if(mp[sum-diff]!=-1)    ans=min(ans,i-mp[sum-diff]);
			mp[sum]=i;
		}
        
		cout<<(ans==n?-1:ans)<<endl;
	}
}