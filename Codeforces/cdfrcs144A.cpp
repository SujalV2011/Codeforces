#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mini,maxi,minval=INT_MAX,maxval=0;;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a<=minval)
        {
            minval=a;
            mini=i;
        }
        if(a>maxval)
        {
            maxval=a;
            maxi=i;
        }
    }
    if(mini<maxi)
        cout<<((n-1)-mini)+maxi-1;
    else
        cout<<((n-1)-mini)+maxi;
}