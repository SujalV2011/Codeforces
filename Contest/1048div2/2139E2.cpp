#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> cnt, pref;
vector<vector<int>> mem, g;
int minh;

void dfs(int u, int p, int h)
{
    if (g[u].size() == 1 && u != 1)
    {
        minh = min(minh, h);
    }
    cnt[h]++;
    for (auto v : g[u])
    {
        if (v == p) continue;
        dfs(v, u, h + 1);
    }
}

int solve(int z, int h, int n)
{
    if (h > minh) return 0;
    if (mem[z][h] != -1) return mem[z][h];
    int o = n - z - (h > 0 ? pref[h - 1] : 0);
    int ans = 0;
    if (o >= cnt[h])
    {
        ans = max(ans, 1 + solve(z, h + 1, n));
    }
    if (z >= cnt[h])
    {
        ans = max(ans, 1 + solve(z - cnt[h], h + 1, n));
    }
    return mem[z][h] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cnt.assign(n + 1, 0);
        pref.assign(n + 1, 0);
        g.assign(n + 1, vector<int>());
        minh = n;
        for (int i = 2; i <= n; i++)
        {
            int p;
            cin >> p;
            g[i].push_back(p);
            g[p].push_back(i);
        }
        dfs(1, -1, 1);
        mem.assign(n + 1, vector<int>(minh + 1, -1));
        for (int i = 1; i <= minh; i++)
        {
            pref[i] = pref[i - 1] + cnt[i];
        }
        cout << solve(k, 1, n) << '\n';
    }
    return 0;
}