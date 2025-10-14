#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin >> n;
        map<ll, ll> up, side, diag1, diag2;
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            up[x]++;
            side[y]++;
            diag1[x-y]++;
            diag2[x+y]++;
        }
        for(auto x : up)
        {
            ans+=x.second*(x.second-1);
        }
        for(auto x : side)
        {
            ans+=x.second*(x.second-1);
        }
        for(auto x : diag1)
        {
            ans+=x.second*(x.second-1);
        }
        for(auto x : diag2)
        {
            ans+=x.second*(x.second-1);
        }
        cout << ans << endl;
    }
}