#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LIMIT = 1000000;
vector<bool> is_prime(LIMIT + 1, true);
vector<long long> prime_squares;

void preprocess() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= LIMIT; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= LIMIT; i++) {
        if (is_prime[i]) 
            prime_squares.push_back(1LL * i * i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preprocess();

    int n;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;
        cout << (binary_search(prime_squares.begin(), prime_squares.end(), x) ? "YES\n" : "NO\n");
    }

    return 0;
}
