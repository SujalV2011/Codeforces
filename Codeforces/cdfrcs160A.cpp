#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,count=0,sum=0,mine=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a, a + n, greater<int>());
    for(int i=0;i<n;i++)
    {
        mine+=a[i];
        count++;
        if(mine>(sum-mine))
        {
            cout<<count;
            return 0;
        }
    }
}