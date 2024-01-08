#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cut = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (b < a)
            {
                cut++;
            }
        }
        cout << cut << '\n';
    }
    return 0;
}