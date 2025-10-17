#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> seg(m);
        for(int i = 0; i < m; i++)
            cin >> seg[i].first >> seg[i].second;

        vector<int> cnt(n + 2, 0);
        for(auto &s : seg)
        {
            cnt[s.first] += 1;
            cnt[s.second + 1] -= 1;
        }

        for(int i = 1; i <= n; i++)
            cnt[i] += cnt[i - 1];

        vector<int> cntCover(n + 1);
        for(int i = 1; i <= n; i++)
            cntCover[i] = cnt[i];

        const int INF = 1e9;
        vector<int> minR(n + 1, INF), maxL(n + 1, -INF);

        for(auto &s : seg)
        {
            int l = s.first, r = s.second;
            for(int a = l; a <= r; a++)
            {
                if(r < minR[a]) 
                    minR[a] = r;
                if(l > maxL[a]) 
                    maxL[a] = l;
            }
        }

        vector<int> bestStart(n + 2, -INF);
        for(auto &s : seg)
        {
            bestStart[s.first] = max(bestStart[s.first], s.second);
        }

        vector<int> prefMaxR(n + 2, -INF);
        for(int i = 1; i <= n; i++)
        {
            prefMaxR[i] = max(prefMaxR[i - 1], bestStart[i]);
        }

        int best_mex = INT_MAX;
        int besta = 1, bestb = 2;

        for(int a = 1; a <= n; a++)
        {
            for(int b = 1; b <= n; b++)
            {
                if(a == b) 
                    continue;

                bool has0 = (cntCover[a] < m);
                int L = min(a, b), R = max(a, b);
                bool has2 = (prefMaxR[L] >= R);
                bool has1;

                if(b > a)
                {
                    has1 = (minR[a] < b);
                }
                else
                {
                    has1 = (maxL[a] > b);
                }

                bool present0 = has0;
                bool present1 = has1;
                bool present2 = has2;

                int mex = 0;

                if(present0)
                {
                    if(present1)
                    {
                        if(present2) 
                            mex = 3;
                        else 
                            mex = 2;
                    }
                    else 
                        mex = 1;
                }
                else 
                    mex = 0;

                if(mex < best_mex)
                {
                    best_mex = mex;
                    besta = a;
                    bestb = b;
                    if(best_mex == 0) 
                        break;
                }
            }
            if(best_mex == 0) 
                break;
        }

        vector<int> ans(n + 1, -1);
        ans[bestb] = 1;
        ans[besta] = 0;
        int cur = 2;

        for(int i = 1; i <= n; i++) if(ans[i] == -1) ans[i] = cur++;

        for(int i = 1; i <= n; i++)
        {
            if(i > 1) cout << ' ';
            cout << ans[i];
        }

        cout << endl;
    }

    return 0;
}
