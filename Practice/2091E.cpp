#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    vector<bool>isprime(1e7+1,true);
    isprime[0]=isprime[1]=false;
    vector<int>prime;
    prime.reserve(664579);
    
    for(int i=2;i<=1e7;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            if(1LL*i*i<=1e7)
            {
                for(int j=i*i;j<=1e7;j+=i)
                    isprime[j]=false;

            }
        }
    }
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        ll ans=0;
        for(auto p:prime)
        {
            if(p>n) break;
            ans+=(n/p);
            // cout<<prime[i]<<" "<<n/prime[i]<<endl;
        }

        cout<<ans<<endl;
    }
}