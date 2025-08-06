#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;

        unordered_map<int, int> cnt;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            sum += x;
            cnt[x]++;
        }

        cout<<cnt[0]+sum<<'\n';
    }
}