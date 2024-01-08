#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i=0,sum=0;
    cin>>n;
    int a[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int j=0;j<3;)
    {
        if(i<n)
        {
            sum+=a[i][j];
            i++;
        }
        else
        {
            i=0;
            j++;
            if(sum==0)
                sum=0;
            else
                break;
        }
    }
    if(sum==0)
        cout<<"YES";
    else
        cout<<"NO";
}