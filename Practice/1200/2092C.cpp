#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; 
        cin >> n;
        vector <int> a(n);
        long long ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
            ans += a[i]; 
            cnt += (a[i] & 1);
        }
        if (!cnt || cnt == n) 
        {
            cout << *max_element(a.begin(), a.end()) << '\n';
        } 
        else 
        {
            cout << ans - cnt + 1 << '\n';
        }
    }
}    