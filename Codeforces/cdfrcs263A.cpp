#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5][5],m,n;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j]==1)
            {
                m=i;n=j;
            }
        }
    }
    if(m<=2 && n<=2)
    {
        cout<<(2-m)+(2-n);
    }
    else if(m>2 && n>2)
    {
        cout<<(m-2)+(n-2);
    }
    else if(m<=2 && n>2)
    {
        cout<<(2-m)+(n-2);
    }
    else 
    {
        cout<<(m-2)+(2-n);
    }
    return 0;
}
