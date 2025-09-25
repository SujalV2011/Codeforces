#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cnt(vector<int>& a, int k, int maxLen)
{
    if (k < 0 || maxLen <= 0) return 0;
    int n = a.size();
    unordered_map<int,int> freq;
    int left = 0;
    ll res = 0;
    int distinct = 0;
    for (int right = 0; right < n; right++)
    {
        if (freq[a[right]] == 0) distinct++;
        freq[a[right]]++;
        while (distinct > k || right - left + 1 > maxLen)
        {
            freq[a[left]]--;
            if (freq[a[left]] == 0) distinct--;
            left++;
        }
        res += (right - left + 1);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll ans = (cnt(a, k, r)-cnt(a, k, l - 1))-(cnt(a, k - 1, r) - cnt(a, k - 1, l - 1));

        cout << ans << "\n";
    }
}
