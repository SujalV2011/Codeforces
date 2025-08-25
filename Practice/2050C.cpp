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
        string s;
        cin >> s;

        vector<int> digits;
        for (char c : s)
        {
            digits.push_back(c - '0');
        }

        int sm = accumulate(digits.begin(), digits.end(), 0);
        int twos = count(digits.begin(), digits.end(), 2);
        int threes = count(digits.begin(), digits.end(), 3);

        bool ok = false;
        for (int i = 0; i <= min(10, twos); i++)
        {
            for (int j = 0; j <= min(10, threes); j++)
            {
                if ((sm + i * 2 + j * 6) % 9 == 0)
                {
                    cout << "YES\n";
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        if (!ok) cout << "NO\n";
    }

    return 0;
}
