#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, capacity = 0, pass = 0;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        pass -= a;
        pass += b;
        capacity = max(capacity, pass);
    }
    cout << capacity;

    return 0;
}