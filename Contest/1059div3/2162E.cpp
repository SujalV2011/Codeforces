#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) 
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
        }
        vector<int> result;
        vector<int> freq(n + 1, 0);
        for (int x : a) 
        {
            freq[x]++;
        }
        int x = 1;
        while (x <= n && freq[x] > 0) 
        {
            x++;
        }
        if (x > n) 
        {
            for (x = 1; x <= n; ++x) 
            {
                if (n >= 2 && (x != a[n-1] && x != a[n-2])) break;
                if (n == 1 && x != a[n-1]) break;
            }
        }
        result.push_back(x);
        for (int i = 1; i < k; ++i) 
        {
            int last = result.back();
            int second_last = (i == 1) ? a[n-1] : result[i-2];
            x = 1;
            while (x <= n && (x == last || x == second_last)) 
            {
                x++;
            }
            if (x > n) x = 1;
            result.push_back(x);
        }
        for (int i = 0; i < k; ++i) 
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}