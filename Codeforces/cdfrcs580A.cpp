#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=1,maxcount=0;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]-a[i]>=0)
            count++;
        else
        {
            maxcount=max(count,maxcount);
            count=1;
        }
    }
    maxcount=max(count,maxcount);
    cout<<maxcount;
    return 0;
}