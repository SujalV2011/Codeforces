#include <bits/stdc++.h>
using namespace std;

long long range_sum(long long l, long long r) 
{
    if (l > r) return 0;
    return (l + r) * (r - l + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        long long n, x, y;
        cin >> n >> x >> y;

        long long l = lcm(x, y);  

        long long plus = n / x - n / l;
        long long minus = n / y - n / l;

        cout << range_sum(n - plus + 1, n) - range_sum(1, minus) << "\n";
    }
    return 0;
}
