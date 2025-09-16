#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k; 
        cin>>n>>k;
        
        vector<int> a(n);
        for (auto& x : a) cin>>x;
    
        map<int, int> cnt;
        for (auto it: a) cnt[it]++;

        bool flg=false;
        for (auto &pr: cnt) 
        {
            if (pr.second%k) 
            {
                cout<<0<<endl; 
                flg=true;
                break;
            }
            pr.second/=k;
        }
        if(flg) continue;
        
        map<int, int> cur;
        ll ans = 0;
        int r = -1;
        for (int l = 0; l<n; l++) 
        {
            while (r+1<n && cur[a[r+1]]+1<=cnt[a[r+1]]) 
            {
                r++; cur[a[r]]++;
            }
            ans+=(r-l+1);
            cur[a[l]]--;
        }
    
        cout<<ans<<endl;
    }
}