#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Observations:

    We can view the conditions and soldiers as a directed graph. The soldiers represent nodes and the conditions represent 
    directed edges. Saying ai should be di meters in front of bi is equivalent to adding two weighted directed edges:

            An edge from ai to bi with weight di.
            An edge from bi to ai with weight −di.

            Now, we iterate over all n soldiers, and do a standard dfs whenever we encounter an unvisited soldier
                assigning coordinates respecting the weights of the edges. 
*/

const ll N = 2e5 + 5;
vector<pair<ll, ll>> adj[N];
ll val[N], vis[N];

void dfs(ll u) 
{
    vis[u] = 1;
    for(auto x: adj[u]) 
    {
        int v = x.first, w = x.second;
        if(!vis[v]) 
        {
            val[v] = val[u] + w;
            dfs(v);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, m; 
        cin >> n >> m;

        for(int i = 1; i <= n; i++) 
        {
            adj[i].clear();
            vis[i] = 0, val[i] = 0;
        }

        vector<array<int, 3>> c;
        for(int i = 1; i <= m; i++) 
        {
            int a, b, d; cin >> a >> b >> d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, -d}); 
            c.push_back({a, b, d});  
        }

        for(int i = 1; i <= n; i++) 
        {
            if(!vis[i]) dfs(i);
        }

        bool flg = true;
        for(int i = 1; i <= m; i++) 
        {
            int a = c[i - 1][0], b = c[i - 1][1], d = c[i - 1][2];
            if(val[a] + d != val[b]) 
            {
                flg = false;
                break;
            }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
}