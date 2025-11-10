#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

/*
    Observations:

        here in the binary string to find the sum of all the median of subsequence of size k
        is that first we require k/2+1 ones then we can select other k/2-1 elements from the remaining n-k/2+1 ones or zeros

        so we can use the combinatorial formula to calculate the number of ways to select k/2-1 elements from n-k/2+1 elements
        so we can run a loop from k/2+1 to n and calculate the number of ways to select k/2-1 elements from n-k/2+1 elements
        and multiply it with k/2+1 and add it to the answer

*/
ll pw(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

ll Comb(ll n, ll k, vector<ll>&fact)
{
    if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod-2)) % mod;
}

int main()
{
    int t;
    cin>>t;
    vector<ll>fact(200001,1);
    for(int i=1;i<=200000;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll ans=0;

        vector<ll>a(n);

        ll ones=0;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            ones+=a[i];
        }

        for(int i=k/2+1;i<=min(ones,k);i++)
        {
            ans += (Comb(ones, i, fact) * Comb(n - ones, k - i, fact) % mod);
			ans %= mod;
        }

        cout<<ans<<endl;
    }
    return 0;
}