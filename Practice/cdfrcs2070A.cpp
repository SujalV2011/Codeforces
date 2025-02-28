#include <iostream>
using namespace std;

typedef long long ll;

// Function to calculate the number of 1s up to index n
ll countOnes(ll n) {
    // Every complete block of 15 contributes 3 ones
    ll fullBlocks = n / 15;
    ll count = fullBlocks * 3;
    
    // Handle remaining elements
    ll remainder = n % 15;
    for (ll i = 0; i <= remainder; i++) {
        if (i % 15 == 0 || i % 15 == 1 || i % 15 == 2) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << countOnes(n) << "\n";
    }
    
    return 0;
}
