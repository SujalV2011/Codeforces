#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) 
    {
        int64 a, b;
        cin >> a >> b;

        int v2 = 0;
        int64 tmp = b;
        while ((tmp & 1LL) == 0) 
        {
            tmp >>= 1;
            ++v2;
        }

        if ((a % 2 == 0) && (b % 2 == 1)) 
        {
            cout << -1 << '\n';
        } 
        else if ((a % 2 == 1) && (v2 == 1)) 
        {
            cout << -1 << '\n';
        } 
        else if ((a % 2 == 1) && (b % 2 == 1)) 
        {
            cout << (a * b + 1) << '\n';
        } 
        else 
        {
            cout << (a * (b / 2) + 2) << '\n';
        }
    }
    return 0;
}
