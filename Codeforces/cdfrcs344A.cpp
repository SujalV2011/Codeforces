#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n,counter=1;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            if(a[i]!=a[i-1])
            {
                counter++;
            }
        }
    }
    cout<<counter;
    return 0;
}