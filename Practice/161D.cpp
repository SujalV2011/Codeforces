#include<bits/stdc++.h>
using namespace std;
/*
    Observation:

    here i have given one tree i want ot find the number of pair of nodes having distance k
    so we can do it by dfs 
        for each node we can find the number of nodes having distance k from it
            we use dp to store the number of nodes at distance k from the current node

    so we can do it in O(n^2) time complexity

*/

void dfs(int node, int par,const vector<vector<int>> &adj,vector<vector<int>> &dp,long long &ans,int k)
{
    dp[node][0] = 1;
    for (int child : adj[node])
    {
        if (child == par) continue;
        dfs(child, node, adj, dp, ans, k);
        for (int i = 0; i < k; ++i)
        {
            int j = k - i - 1;
            ans += 1LL * dp[node][i] * dp[child][j];
        }
        for (int i = 0; i < k; ++i)
        {
            dp[node][i + 1] += dp[child][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    long long ans = 0;

    dfs(1, -1, adj, dp, ans, k);

    cout << ans << endl;
    return 0;
}
