#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int r,k;
    cin>>k>>r;
    for(int i=1;;i++)
    {
        if(((k*i)-r)%10==0 || (k*i)%10==0)
        {
            cout<<i;
            return 0;
        }
    }
}