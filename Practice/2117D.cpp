#include <bits/stdc++.h>
using namespace std;
/*

    Observations:

    -> here in this question we need to perform some amount of op1 and some amount of op2

        so let we perform x times op1 and y times op2

            a[1] = 1*x + n*y --(1)

            a[2] = 2*x + (n-1)*y --(2)
            
            a[n] = n*x + 1*y --(n)
                
                now we take first and last index
                    a[1] = 1*x + n*y  --(1)
                    a[n] = n*x + 1*y  --(2)

    -> now we solve these two equations
            we get
                x = (n*a[n] - a[1])/(n*(n - 1))
                y = (n*a[1] - a[n])/(n*(n - 1))

            now we need to check if x and y are non-negative integers

                if yes then we need to check for all other indexes if they satisfy the equation
                    if yes then print YES else NO
            
                else print NO

*/

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;
        vector < long long > a(n);
        long long divi = n * n - 1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }


        long long p = n * a[n - 1] - a[0];
        long long q = n * a[0] - a[n - 1];

        if (p < 0 || q < 0 || p % divi !=0 || q % divi != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        long long x = p / divi;
        long long y = q / divi;

        bool flg = true;

        for (int i = 1; i <= n; i++)
        {
            if (a[i - 1] != ((x * i) + (y * (n - i + 1))))
            {
                flg = false;
                break;
            }
        }

        if(flg)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}