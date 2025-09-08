#include <bits/stdc++.h>
using namespace std;

vector<int> computeOperations(unsigned long long choc, unsigned long long van) {
    vector<int> ops;
    while (choc != van) 
    {
        if (choc < van) 
        {
            ops.push_back(1);
            van -= choc;
            choc *= 2;
        } 
        else 
        {
            ops.push_back(2);
            choc -= van;
            van *= 2;
        }
    }
    reverse(ops.begin(), ops.end());
    return ops;
}

void processTestCase(long long k, unsigned long long x) 
{
    unsigned long long total = 1ULL << (k + 1);
    unsigned long long choc = x;
    unsigned long long van = total - x;

    vector<int> ops = computeOperations(choc, van);

    cout << ops.size() << "\n";
    for (size_t i = 0; i < ops.size(); ++i) 
    {
        if (i) cout << ' ';
        cout << ops[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        long long k;
        unsigned long long x;
        cin >> k >> x;
        processTestCase(k, x);
    }

    return 0;
}
