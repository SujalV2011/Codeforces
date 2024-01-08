#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[3][3],total=198,temp=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<3;i++)
        {
            temp=0;
            for(int j=0;j<3;j++)
            {
                if(a[i][j]!='?')
                    temp+=a[i][j];
            }
            if(temp!=total)
            {
                cout<<char(total-temp)<<endl;
                break;
            }
        }
    }
    return 0;
}