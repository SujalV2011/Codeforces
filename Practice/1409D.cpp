#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sum(ll n) 
{
	int res = 0;
	while (n > 0) 
    {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() 
{
	int t;
	cin >> t;
	while (t--) 
    {
		ll n;
		int s;
		cin >> n >> s;
		ll ans = 0;
		
		if (sum(n) <= s) 
        {
			cout << 0 << endl;
			continue;
		}
		
		ll pw = 1;
		for(int i = 0; i < 18; i++) 
        {
			int digit = (n / pw) % 10;
			ll add = pw * ((10 - digit) % 10);
			n += add;
			ans += add;
			
			if (sum(n) <= s) 
            {   
				break;
			}
			
			pw *= 10;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
