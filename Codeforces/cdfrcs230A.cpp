#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> dragons;
    for (int i = 0; i < n; i++)
    {
        int strength, bonus;
        cin >> strength >> bonus;
        dragons.push_back(make_pair(strength, bonus));
    }
    sort(dragons.begin(), dragons.end());
    for (int i = 0; i < n; i++)
    {
        if (s > dragons[i].first)
            s += dragons[i].second;
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}