#include<bits/stdc++.h>
using namespace std;
using ll = long long;


/*
            1    2   3
              
               4    5    7

                6     8
        i need to find the shortest path from n-1 nodes to 1 
        so i use bfs to store the shrtest distance and will start the 1 node itself as finding shortest path form any other node to the 1
        
    
*/

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> arr(n+1), ans(k+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    vector<int> dist(n+1, 1e9);

    dist[1] = 0;
    q.push(1);

    vector<bool> vis(n+1, false);
    vis[1] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int x : graph[node])
        {
            if(!vis[x])
            {
                vis[x] = true;
                dist[x] = dist[node] + 1;
                q.push(x);
            }
        }
    }

    unordered_map<int, vector<int>> mp;
    for(int i=1;i<=n;i++)
        mp[arr[i]].push_back(dist[i]);

    for(auto &x : mp)
        ans[x.first] = *max_element(x.second.begin(), x.second.end());

    for(int i=1;i<=k;i++)
        cout<<ans[i]<<" ";
}



