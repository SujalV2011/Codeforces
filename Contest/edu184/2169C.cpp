#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<ll> a(n + 1), pref(n + 1);
        for(int i = 1; i <= n; i++) 
        {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }

        ll original_sum = pref[n];

        ll best_gain = 0;  
        ll best_G = LLONG_MIN;  
        for(int r = 1; r <= n; r++) 
        {
            ll temp1 = pref[r - 1] - 1LL * r * r + r;
            best_G = max(best_G, temp1);

            ll temp2 = 1LL * r * r + r - pref[r];

            best_gain = max(best_gain, best_G + temp2);
        }

        cout << original_sum + best_gain << endl;
    }
    return 0;
}
