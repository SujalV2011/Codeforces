#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int stpcount=0;
    while(x!=0)
    {
        if(x>=5)
        {
            x=x-5;
            stpcount++;
            continue;
        }
        if(x>=4)
        {
            x=x-4;
            stpcount++;
            continue;
        }
        if(x>=3)
        {
            x=x-3;
            stpcount++;
            continue;
        }
        if(x>=2)
        {
            x=x-2;
            stpcount++;
            continue;
        }
        if(x>=1)
        {
            x=x-1;
            stpcount++;
            continue;
        }
    };
    cout<<stpcount;
    return 0;
}