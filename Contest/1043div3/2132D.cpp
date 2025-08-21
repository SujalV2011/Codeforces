#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sumDigits(ll n)
{
    if (n < 10) return n * (n + 1) / 2;
    string s = to_string(n);
    int d = s.size();
    ll p = 1;
    for (int i = 1; i < d; i++) p *= 10;
    ll msd = n / p;
    ll rem = n % p;
    ll res = msd * (msd - 1) / 2 * p;
    res += msd * (rem + 1);
    res += sumDigits(rem);
    res += msd * (d - 1) * (p / 10) * 45;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        ll len = 1, cnt = 9, start = 1;
        while (k > len * cnt)
        {
            k -= len * cnt;
            len++;
            cnt *= 10;
            start *= 10;
        }
        ll num = start + (k - 1) / len;
        ll pos = (k - 1) % len;
        ll upto = num - 1;
        ll ans = sumDigits(upto);
        string snum = to_string(num);
        for (int i = 0; i <= pos; i++) ans += snum[i] - '0';
        cout << ans << '\n';
    }
    return 0;
}
