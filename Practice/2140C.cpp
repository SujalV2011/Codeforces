#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
	int t;
	cin >> t;
	while(t--)
    {
        ll n;
		cin >> n;
        vector<ll>a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		
        ll ans=0;
		ll mx=0;
        ll mx2=-1e18,mn1=1e18;

		for(int i=0; i<n; i++)
        {
			if(i%2==0)
            {
				ans+=a[i];
				mn1=min(mn1,2*a[i]+i);
				mx=max(mx,mx2-2*a[i]+i);
			}
			else
            {
				ans-=a[i];
				mx2=max(mx2,2*a[i]-i);
				mx=max(mx,2*a[i]+i-mn1);
			}
        }

		if(n%2) 
            mx=max(mx,n-1);
		else 
            mx=max(mx,n-2);

		cout << ans+mx << endl;
	}
	return 0;
}
