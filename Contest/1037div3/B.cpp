#include <iostream>
#include <vector>
using namespace std;

int maxHikes(int n, int k, const vector<int>& a) {
    int count = 0;
    int i = 0;

    while (i <= n - k) {
        // Check if from i to i+k-1 all days are good weather (i.e., a[j] == 0)
        bool canHike = true;
        for (int j = 0; j < k; ++j) {
            if (a[i + j] != 0) {
                canHike = false;
                break;
            }
        }

        if (canHike) {
            count++;
            i += k + 1;  // Skip k days of hike and 1 day of break
        } else {
            i++;  // Try next starting day
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << maxHikes(n, k, a) << '\n';
    }
    return 0;
}
