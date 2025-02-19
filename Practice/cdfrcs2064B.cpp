#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void findRange(vector<int>& a, int n) {
    vector<int> freq(n + 1);
    for (int x : a) freq[x]++;

    vector<int> len(n + 1);
    len[0] = freq[a[0]] == 1;
    
    for (int i = 1; i < n; i++) {
        if (freq[a[i]] == 1)
            len[i] = len[i - 1] + 1;
    }

    int mx = *max_element(len.begin(), len.end());
    if (mx == 0) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (len[i] == mx) {
            cout << i - len[i] + 2 << " " << i + 1 << "\n";
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& x : arr) cin >> x;

        findRange(arr, n);
    }

    return 0;
}
