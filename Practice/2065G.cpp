#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    vector<bool>is_prime(2*1e5+1,true);
    is_prime[0]=is_prime[1]=false;

    for(int i=2;i*i<=2*1e5;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=2*1e5;j+=i)
            {
                is_prime[j]=false;
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>arr(n);
        
        for(int i=0;i<n;i++) cin>>arr[i];

        ll cnt=0;
        ll one=0;
        unordered_map<ll,pair<ll,bool>>mp;
        for(int i=0;i<n;i++)
        { 
            if(arr[i]==1) one++;
            mp[arr[i]].first++;
            mp[arr[i]].second=false; 
        }
        // sort(arr.begin(),arr.end());
        // for(int i=0;i<n;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
        ll sum=0;
        ll temp=0;
        for(auto& x:mp)
        {   
            if(is_prime[x.first])
            {
                sum+=(temp*x.second.first);
                temp+=x.second.first;
            }
        }
        // cout<<sum<<endl;
        // cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=1 && !is_prime[arr[i]] && !mp[arr[i]].second)
            {
                bool flg=false;
                mp[arr[i]].second=true;
                for(int j=2;j*j<=arr[i];j++)
                {
                    if(is_prime[j] && arr[i]%j==0 && is_prime[arr[i]/j])
                    {
                        ll temp=arr[i]/j;
                        if(j==temp) sum += (mp[j].first * mp[arr[i]].first);
                        else
                        {
                            sum += (mp[temp].first*mp[arr[i]].first);
                            sum += (mp[j].first*mp[arr[i]].first);
                        } 
                        flg=true;
                    }
                }
                if(flg)
                {
                    auto p=mp[arr[i]];
                    sum += (one*mp[arr[i]].first);
                    sum+=mp[arr[i]].first;
                    sum+=(p.first*(p.first-1))/2;
                }
            }
        }
        cout<<sum<<endl;        
    }
}