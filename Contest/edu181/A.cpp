#include<bits/stdc++.h>
using namespace std;
#define  ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int countT = 0;
        string rest;
        for (char c : s) {
            if (c == 'T') countT++;
            else rest += c;
        }
        for (int i = 0; i < countT; ++i) cout << 'T';
        cout << rest << '\n';
    }
    return 0;
}