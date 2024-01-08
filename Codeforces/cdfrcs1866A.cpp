#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],min;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    min=abs(a[0]);
    for(int i=1;i<n;i++)
    {
        if(abs(a[i])<min)
            min=abs(a[i]);
    }
    cout<<min;
    return 0;
}