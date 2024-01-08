#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,crime=0,recruit=0,uncheck=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            crime=a[i];
            if(recruit-abs(crime)<0)
                uncheck++;
            else
                recruit-=abs(crime);
        }
        else
        {
            if(recruit==0)
                recruit=a[i];
            else
                recruit+=a[i];
        }
    }
    cout<<uncheck;
    return 0;
}