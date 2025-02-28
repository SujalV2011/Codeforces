#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countGoodPairs(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    vector<int> d(n);

    for (int i = 0; i < n; i++)
    {
        d[i] = a[i] - b[i];
    }

    sort(d.begin(), d.end());

    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        if(d[i]<=0) continue;
        long long j = lower_bound(d.begin(), d.end(), -d[i]+1) - d.begin();
        count += (i - j);
    }

    return count;
}

int main()
{

    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << countGoodPairs(a, b) << endl;

    return 0;
}
