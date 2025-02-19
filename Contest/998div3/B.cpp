#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define mod 1000000007

vector<string> process(int t, vector<tuple<int, int, vector<vector<int>>>>& data) 
{
    vector<string> res;
    for (auto& d : data) 
    {
        int n, m;
        vector<vector<int>> decks;
        tie(n, m, decks) = d;
        for (auto& deck : decks) sort(deck.begin(), deck.end());
        vector<pii> sc;
        for (int i = 0; i < n; ++i) sc.emplace_back(decks[i][0], i);
        sort(sc.begin(), sc.end());
        vi order;
        for (auto& p : sc) order.push_back(p.second + 1);
        bool valid = true;
        int top = -1;
        for (int r = 0; r < m && valid; r++) 
        {
            for (int cow : order) 
            {
                int idx = cow - 1;
                if (!decks[idx].empty() && decks[idx][0] > top) 
                {
                    top = decks[idx][0];
                    decks[idx].erase(decks[idx].begin());
                } 
                else 
                {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) 
        {
            stringstream ss;
            for (int i = 0; i < (int)order.size(); i++) 
            {
                ss << order[i] << (i + 1 < (int)order.size() ? " " : "");
            }
            res.push_back(ss.str());
        } 
        else 
        {
            res.push_back("-1");
        }
    }
    return res;
}

int main() {
    fastio();
    int t;
    cin >> t;
    vector<tuple<int, int, vector<vector<int>>>> data;
    for (int i = 0; i < t; ++i) 
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> decks(n, vector<int>(m));
        for (int j = 0; j < n; ++j) 
        {
            for (int k = 0; k < m; ++k) 
            {
                cin >> decks[j][k];
            }
        }
        data.emplace_back(n, m, decks);
    }
    vector<string> res = process(t, data);
    for (const auto& r : res) cout << r << "\n";
    return 0;
}
