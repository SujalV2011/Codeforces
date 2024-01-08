#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s=0;
        cin>>n;
        int a[2*n];
        for(int i=0;i<2*n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+(2*n));
        for(int i=0;i<n-1;i++)
        {
            s+=(abs(a[n-i-1]-a[n-i-2])+abs(a[n+i]-a[n+i+1]));
        }
        cout<<s<<endl;
        for(int i=0;i<n;i++)
            cout<<a[n-i-1]<<" "<<a[n+i]<<endl;
    }
    return 0;
}