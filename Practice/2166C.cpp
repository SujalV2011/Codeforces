#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {

        int n;
        cin >> n;
    
        if (n == 1) 
        {
            int temp;
            cin >> temp;
            cout << 0 << endl;
            return 0;
        }
    
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
    
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) 
        {
            left[i] = (i - 1 + n) % n;
            right[i] = (i + 1) % n;
        }
    
        vector<bool> alive(n, true);
    
        priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> pq;
    
        for (int i = 0; i < n; ++i) 
        {
            int j = right[i];
            pq.push({max(a[i], a[j]), i, j});
        }
    
        ll ans = 0;
        int rem = 0;
    
        while (rem < n - 1) 
        {
    
            auto [cost, i, j] = pq.top();
            pq.pop();
    
            if (!alive[i] || !alive[j]) continue;
    
            ans += cost;
            rem++;
    
            alive[j] = false;
    
            a[i] = max(a[i], a[j]);
    
            int l_i = left[i];
            int r_j = right[j];
    
            right[l_i] = i;
            left[r_j] = i;
            left[i] = l_i;
            right[i] = r_j;
    
            pq.push({max(a[l_i], a[i]), l_i, i});
            pq.push({max(a[i], a[r_j]), i, r_j});
        }
    
        cout << ans << endl;
    }
    
    return 0;
}
