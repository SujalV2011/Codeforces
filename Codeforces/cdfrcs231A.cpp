#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][3],b,c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        b=0;
        for(int j=0;j<3;j++)
        {
            b=b+a[i][j];
        }
        if(b>=2)
          c++;    
    }
    cout<<c;
}