#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200000;
vector<vector<int>> pfac(N + 1);

int main() 
{
    for(int i=2;i<=N;i++) 
    {
        if (pfac[i].empty()) 
        {
            for (int j=i;j<=N;j+=i)
                pfac[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        int ans = 2;
        map<int, int> cnt;

        for (int i = 0; i < n; i++) 
        {
            for (int p : pfac[a[i]]) 
            {
                if (cnt[p] > 0) ans = 0;
                cnt[p]++;
            }
        }

        for (int i = 0; i < n; i++) 
        {
            for (int p : pfac[a[i]])    cnt[p]--;

            for (int p : pfac[a[i] + 1]) 
            {
                if (cnt[p] > 0) ans = min(ans, 1);
            }
            
            for (int p : pfac[a[i]])    cnt[p]++;
        }

        cout << ans << endl;
    }
}
