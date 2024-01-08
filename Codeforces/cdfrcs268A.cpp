#include<iostream>
using namespace std;
int main()
{
    int n,e=0,od=0;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
        {
            e++;
        }
        else
        {
            od++;
        }
    }
    if(e>od)
    {
        for(int i=0; i<n; i++)
        {
            if(a[i]%2!=0)
            {
                cout<<i+1;
                break;
            }
        }
    }
    else
            {
        for(int i=0; i<n; i++)
        {
            if(a[i]%2==0)
            {
                cout<<i+1;
                break;
            }
        }
    }
    return 0;
}