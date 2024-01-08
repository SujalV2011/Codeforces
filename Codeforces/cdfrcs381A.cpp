#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int n,sumS=0,sumD=0;
    cin>>n;    
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int l=0,r=n-1,i=1;
    while(l<=r)
    {
        if(i%2!=0)
        {
            if(a[l]>a[r])
                sumS+=a[l++];
            else    
                sumS+=a[r--];
        }
        else
        {
            if(a[l]>a[r])
                sumD+=a[l++];
            else    
                sumD+=a[r--];
        }
        i++;
    }
    cout<<sumS<<" "<<sumD<<endl;
    return 0;
}