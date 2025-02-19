#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;

        int maxFibonacciness = 0;

        int fibCount1 = 1;
        int a3_option1 = a1 + a2;
        if (a4 == a2 + a3_option1) 
        {
            fibCount1++;
        }
        if (a5 == a3_option1 + a4) 
        {
            fibCount1++;
        }

        int fibCount2 = 0;
        int a3_option2 = a5 - a4;
        if (a4 == a2 + a3_option2) 
        {
            fibCount2++;
        }
        if (a5 == a3_option2 + a4) 
        {
            fibCount2++;
        }

        maxFibonacciness = max(fibCount1, fibCount2);

        cout << maxFibonacciness << endl;
    }

    return 0;
}
