#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
	cin>>t;
	while(t--)
	{
	    ll n,l,r,k;
		cin>>n>>l>>r>>k;
		if(n%2==1)
		{
			cout<<l<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<-1<<endl;
			continue;
		}
		ll res=1;
		bool fl=0;
		while(res<=r)
		{
			if(res>l)
			{
				fl=1;
				if(k<=n-2)
				 cout<<l<<endl;
				else
				 cout<<res<<endl;
				break;
			}
			res*=2;
		}
		if(!fl)
		 cout<<-1<<endl;
	}
}