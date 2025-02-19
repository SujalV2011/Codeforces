#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<long long>> arr(n, vector<long long>(m));
    vector<long long> rowSum(n);
    
    for (int i = 0; i < n; i++) 
    {
        long long sum = 0;
        for (int j = 0; j < m; j++) 
        {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        rowSum[i] = sum;
    }
    
    vector<int> index(n);
    iota(index.begin(), index.end(), 0);
    sort(index.begin(), index.end(), [&](int i, int j) 
    {
        return rowSum[j] < rowSum[i];
    });
    
    long long result = 0, cumulativeSum = 0;
    for (int i = 0; i < n; i++) 
    {
        int idx = index[i];
        for (int j = 0; j < m; j++) 
        {
            cumulativeSum += arr[idx][j];
            result += cumulativeSum;
        }
    }
    
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
