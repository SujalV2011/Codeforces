#include <bits/stdc++.h>
#define yes cout << YES << endl
#define no cout << NO << endl
#define fi(s, e) for (int i = s; i < e; i++)
#define fj(s, e) for (int j = s; j < e; j++)
#define fk(s, e) for (int k = s; k < e; k++)
using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    fi(0, n)
    {
        if (i % 2 == 0)
        {
            fj(0, m)
            {
                cout << "#";
            }
            cout << endl;
        }
        else
        {
            static int count = 0;
            if (count % 2 == 0)
            {
                fj(0, m - 1)
                {
                    cout << ".";
                }
                cout << "#" << endl;
                count++;
            }
            else
            {
                cout << "#";
                fj(0, m - 1)
                {
                    cout << ".";
                }
                cout<<endl;
                count++;
            }
        }
    }
    return 0;
}