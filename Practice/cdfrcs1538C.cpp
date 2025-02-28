#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n);

        for (int &e : v)
        {
            cin >> e;
        }

        sort(v.begin(), v.end());
        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += upper_bound(v.begin(), v.end(), r - v[i]) - v.begin();
            ans -= lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();
            if (l <= 2 * v[i] && 2 * v[i] <= r)
            {
                ans--;
            }
        }

        cout << ans / 2 << "\n";
    }

    return 0;
}
