// This program is made by Sujal Vekariya
#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define trav(x, v) for (auto &x : v)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
#define desync() cout.flush(), system("pause"), _Exit(0)

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool isSq(ll x)
{
    ll s = sqrt(x);
    return s * s == x;
}

vi genPerm(int n)
{
    ll sum = (1LL * n * (n + 1)) / 2;
    if (isSq(sum))
        return {-1};

    set<int, greater<int>> avail;
    for (int i = 1; i <= n; i++)
    {
        avail.insert(i);
    }
    vi p;
    ll preSum = 0;
    while (!avail.empty())
    {
        for (auto it = avail.begin(); it != avail.end(); it++)
        {
            if (!isSq(preSum + *it))
            {
                p.pb(*it);
                preSum += *it;
                avail.erase(it);
                break;
            }
        }
    }
    return p;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi res = genPerm(n);
        if (res.size() == 1 && res[0] == -1)
        {
            cout << "-1\n";
        }
        else
        {
            for (int num : res)
            {
                cout << num << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
