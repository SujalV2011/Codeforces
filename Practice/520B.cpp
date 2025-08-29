#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int ans=0;
	while(m!=n)
	{
		if(m<n||m%2) m++,ans++;
		else m/=2,ans++;
	}
	cout<<ans;
}
