#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXX = 21;
    vector<long long> pow3(MAXX), cost(MAXX);
    pow3[0] = 1;
    for (int i = 1; i < MAXX; i++)
    {
        pow3[i] = pow3[i-1] * 3;
    }
    for (int x = 0; x < MAXX-1; x++)
    {
        if (x == 0)
        {
            cost[x] = 3;
        }
        else
        {
            cost[x] = pow3[x+1] + 1LL * x * pow3[x-1];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long ans = 0;
        for (int x = MAXX-1; x >= 0; x--)
        {
            if (pow3[x] > n) continue;
            long long d = n / pow3[x];
            ans += d * cost[x];
            n -= d * pow3[x];
        }
        cout << ans << "\n";
    }
    return 0;
}
