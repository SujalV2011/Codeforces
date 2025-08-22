#include<bits/stdc++.h>
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

        vector<ll> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        ll ans=0;
        
        sort(a.begin(), a.end());
        ll mx=a[n-1];
        for(int i=n-1;i>=2;i--)
        {
            for(int j=i-1;j>=1;j--)
            {
                // for(int k=0;k<j;k++)
                // {
                //     if(i==n-1 && a[i]<a[j]+a[k])
                //     {
                //         ans+=j-k;
                //         break;
                //     }
                //     else if(mx<a[i]+a[j]+a[k] && a[i]<a[j]+a[k])
                //     {
                //         ans+=j-k;
                //         break;
                //     }
                // }
                //binary search the lowest index which if i==n-1 && a[i]<a[j]+a[k] or mx<a[i]+a[j]+a[k] && a[i]<a[j]+a[k]
                //how can i use lower_bound here?
                auto it = lower_bound(a.begin(), a.begin() + j, max(a[i] - a[j] + 1, (i == n - 1 ? a[i] - a[j] + 1 : mx - a[i] - a[j] + 1)));
                if(it != a.begin() + j)
                    ans += (j - (it - a.begin()));

                // int low=0,high=j-1,mid;
                // int idx=-1;
                // while(low<=high)
                // {
                //     mid=low +(high-low)/2;
                //     if(i==n-1 && a[i]<a[j]+a[mid])
                //     {
                //         idx=mid;
                //         high=mid-1;
                //     }
                //     else if(mx<a[i]+a[j]+a[mid] && a[i]<a[j]+a[mid])
                //     {
                //         idx=mid;
                //         high=mid-1;
                //     }
                //     else
                //         low=mid+1;
                // }
                // if(idx!=-1)
                //     ans+=j-idx;
            }
        }

        cout << ans << "\n";
    }
}