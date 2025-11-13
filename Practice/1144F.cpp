#include<bits/stdc++.h>
using namespace std;

//observations
/*
    here we will be given an undirected graph of n vertices and m edges.
    we need to find the cycles in the components of the graph if there is a cycle of odd length then the answer is no
    else the answer is yes
    to find the cycles we can use idea of bipartite graph
    a bipartite graph is a graph whose vertices can be divided into two disjoint and
    independent sets U and V such that every edge connects a vertex in U to one in V.
       if the answer is not we will start with 1 we will check if there is any edge that is pointing to 1 or not if pointing towards 1 then we will make every edhe to its adjacent node in reverse
       
       like if 1 2 3 4 forms cycle then we habe edges:

        1->2 
        1->4
        3->2 
        3->4

        now we will use map to to store the directed edges pair so we will have map of 1->2 , 1->4 , 3->2 , 3->4
        then we will print 0 if the edge is present in the map else we will print 1
        and these edges wiil be from the input edges
*/

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<pair<int, int>> e;

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
        e.push_back({x, y});
    }

    vector<int> color(n, -1);
    bool bipartite = true;

    for (int i = 0; i < n && bipartite; ++i)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            color[i] = 0;
            q.push(i);
            while (!q.empty() && bipartite)
            {
                int v = q.front();
                q.pop();
                for (auto to : g[v])
                {
                    if (color[to] == -1)
                    {
                        color[to] = color[v] ^ 1;
                        q.push(to);
                    }
                    else if (color[to] == color[v])
                    {
                        bipartite = false;
                        break;
                    }
                }
            }
        }
    }

    if (!bipartite)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (auto [u, v] : e)
    {
        cout << (color[u] < color[v]);
    }
    cout << "\n";

    return 0;
}




