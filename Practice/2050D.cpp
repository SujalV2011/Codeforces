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

        for (int i = 0; i < (int)s.size(); i++)
        {
            int best = s[i] - '0';
            int pos = i;

            for (int j = i; j < min(i + 10, (int)s.size()); j++)
            {
                if (s[j] - '0' - (j - i) > best)
                {
                    best = s[j] - '0' - (j - i);
                    pos = j;
                }
            }

            while (pos > i)
            {
                swap(s[pos], s[pos - 1]);
                pos--;
            }

            s[i] = char(best + '0');
        }

        cout << s << '\n';
    }

    return 0;
}
