#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) 
    {
        int k;
        cin >> k;
        if (k == 0) 
        {
            cout << 1 << "\n";
            cout << "0 0\n";
            continue;
        }
        vector<int> groups;
        int rem = k;
        while (rem > 0) 
        {
            for (int m = 500; m >= 2; m--)
            {
                int tri = m * (m - 1) / 2;
                if (tri <= rem) 
                {
                    groups.push_back(m);
                    rem -= tri;
                    break;
                }
            }
        }
        int total = 0;
        for (int g : groups) total += g;
        cout << total << "\n";
        for (int i = 0; i < (int)groups.size(); i++)
         {
            int g = groups[i];
            int baseX = i * 1000;
            int y = i;
            for (int j = 0; j < g; j++) 
            {
                cout << (baseX + j) << " " << y << "\n";
            }
        }
    }
    return 0;

}