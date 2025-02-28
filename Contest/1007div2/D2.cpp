#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> a, pre;
unordered_map<ll, int> memo;

void preprocess()
{
    pre[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] ^ a[i];
    }
}

int F(ll x)
{
    if (x <= n)
        return pre[(int)x];
    if (memo.count(x))
        return memo[x];
    int res;
    if (n % 2 == 1)
    {
        if (x % 2 == 1)
        {
            res = pre[n];
        }
        else
        {
            res = pre[n] ^ F(x / 2);
        }
    }
    else
    {
        if (x % 2 == 1)
        {
            res = pre[n] ^ pre[n / 2];
        }
        else
        {
            res = pre[n] ^ pre[n / 2] ^ F(x / 2);
        }
    }
    memo[x] = res;
    return res;
}

int solve(ll x)
{
    if (x <= n)
    {
        return a[(int)x];
    }
    else
    {
        return F(x / 2);
    }
}

int get_sum(ll l, ll r)
{
    int sum = 0;
    for (ll i = l; i <= r; i++)
    {
        sum += solve(i);
    }
    return sum;
}

void process_test_case()
{
    ll l, r;
    cin >> n >> l >> r;
    a.assign(n + 1, 0);
    pre.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    preprocess();
    memo.clear();
    cout << get_sum(l, r) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        process_test_case();
    }
    return 0;
}
