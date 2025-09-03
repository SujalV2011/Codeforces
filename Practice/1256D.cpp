#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        string res = s;
        ll ones = 0;
        vector<char> ans(n, '1');

        for (int i = 0; i < n; i++) 
        {
            if (s[i] == '1') 
            {
                ones++;
            } 
            else 
            {
                ll shift = min(k, (ll)ones);
                ans[i - shift] = '0';
                k -= shift;
            }
        }

        for (int i = 0; i < n; i++) 
        {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
