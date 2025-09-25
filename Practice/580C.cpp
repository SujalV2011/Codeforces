#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+5;
int m, a[N];
vector<int> g[N];
int ans;
void dfs(int u, int p, int cnt)
{
    if(cnt>m) return;
    if(u!=1&&g[u].size()==1) ans++;
    for(auto v : g[u]) if(v!=p) dfs(v, u, a[v]?cnt+1:0);
}
int main()
{
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, a[1]);
    cout<<ans<<'\n';
}
