#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<bool> isPrime(MAX_N+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_N; i++)
    {
        if(isPrime[i])
        {
            for (int j = i * i; j <= MAX_N; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> allPrimes;
    for (int i = 2; i <= MAX_N; i++)
    {
        if(isPrime[i]) 
        {
            allPrimes.push_back(i);
        }
    }
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> freq(n+1, 0);
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x <= n) 
                freq[x]++;
        }

        long long ans = 0;

        for (int p : allPrimes) 
        {
            if(p > n) break;
            long long sq = (long long)p * p;
            long long countP = freq[p];
            if(sq <= n)
            {
                long long countSq = freq[sq];
                ans += countP * countSq + (countSq * (countSq + 1LL)) / 2;
            }
        }

        vector<int> primes;
        for (int p : allPrimes)
        {
            if(p > n) break;
            primes.push_back(p);
        }
        int m = (int)primes.size();

        vector<long long> suf(m+1, 0);
        for (int i = m-1; i >= 0; i--)
        {
            suf[i] = suf[i+1] + freq[primes[i]];
        }

        for (int i = 0; i < m; i++)
        {
            int p = primes[i];
            long long countP = freq[p];
            int T = n / p;

            int lowIndex = i + 1;
            int highIndex = (int)(upper_bound(primes.begin() + lowIndex, primes.end(), T) - primes.begin());

            for (int j = lowIndex; j < highIndex; j++)
            {
                int q = primes[j];
                long long countQ = freq[q];
                int prod = p * q;
                long long countProd = freq[prod];
                long long add = countP * countQ;
                add += countQ * countProd;
                add += countP * countProd;
                add += (countProd * (countProd + 1LL)) / 2;
                ans += add;
            }

            if(highIndex < m)
            {
                long long sumFreq = suf[highIndex];
                ans += countP * sumFreq;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
