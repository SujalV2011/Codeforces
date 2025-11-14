#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();

        bool inf=false;
        for(int i=0;i<n-1;i++)
        {
            if(s[i] != '<' && s[i+1] != '>')
            {
                inf=true;
                break;
            }
        }
        if(inf)
        {
            cout<<-1<<"\n";
            continue;
        }

        vector<vector<int>> g(n+2);
        vector<int> indeg(n+2,0);

        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='<')
            {
                int to = (i==1?0:i-1);
                g[i].push_back(to);
                indeg[to]++;
            }
            else if(s[i-1]=='>')
            {
                int to = (i==n? n+1 : i+1);
                g[i].push_back(to);
                indeg[to]++;
            }
            else
            {
                int to1 = (i==1?0:i-1);
                int to2 = (i==n? n+1:i+1);
                g[i].push_back(to1);
                g[i].push_back(to2);
                indeg[to1]++;
                indeg[to2]++;
            }
        }

        queue<int> q;
        for(int i=0;i<=n+1;i++)
            if(indeg[i]==0) q.push(i);

        vector<int> topo;
        while(!q.empty())
        {
            int u=q.front(); 
            q.pop();
            topo.push_back(u);
            for(int v:g[u])
            {
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        vector<ll> dp(n+2,0);

        for(int i=topo.size()-1;i>=0;i--)
        {
            int u=topo[i];
            if(u==0 || u==n+1) continue;
            if(s[u-1]=='<')
            {
                int to = (u==1?0:u-1);
                dp[u] = 1 + dp[to];
            }
            else if(s[u-1]=='>')
            {
                int to = (u==n? n+1: u+1);
                dp[u] = 1 + dp[to];
            }
            else
            {
                ll v1 = dp[(u==1?0:u-1)];
                ll v2 = dp[(u==n? n+1:u+1)];
                dp[u] = 1 + max(v1,v2);
            }
        }

        ll ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);

        cout<<ans<<"\n";
    }
}
