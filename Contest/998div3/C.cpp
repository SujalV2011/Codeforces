#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) 
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        map<int, int> freq;
        for (int i=0;i<nums.size();i++) freq[nums[i]]++;

        int score = 0;
        for (int i=0;i<n;i++) 
        {
            if (freq[nums[i]] > 0) 
            {
                int complement = k - nums[i];
                if (freq[complement] > 0) 
                {
                    if (nums[i] == complement && freq[nums[i]] < 2) continue;
                    freq[nums[i]]--;
                    freq[complement]--;
                    score++;
                }
            }
        }

        cout << score << endl;
    }
    return 0;
}
