#include<bits/stdc++.h>
using namespace std;
using ll= long long;

/*
    Observations:

    here we can observ that we need to take the pairs of visiter but with the greedy startegy ie

    if k==1 then tkae the sum of the n pairs 
    if k==2 then fix index 1 and 2n as the start and end time of the one person and add all the other pirs 
    if k==3 then fix k-1 pairs ie 1 and 2n 2 and 2n-1 and sum of the pairs 
    so if we notice then we can find the sum of the pairs using prefix sums of the pairs in O(1) time 

    so this is the greedy strategy...
*/

int main()
{
    ll t;
	cin>>t;
	while(t--)
    {
        ll n;
		cin>>n;
        vector<ll>a(2*n+1),s(2*n+1),m(2*n+1);
		for(int i=1;i<=n*2;i++)
        {
			cin>>a[i];
			s[i]=s[i-1]+a[i];
			m[i]=a[i]-m[i-1];
		}
		for(int k=1;k<=n;k++)
        {
			cout<<s[n*2]-s[n*2-k+1]-s[k-1]+(m[n*2-k+1]-m[k-1])<<" ";
		}
		cout<<endl;
	}
}