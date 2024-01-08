#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,k,step=0;
        cin>>x>>y>>k;
        if(y>x)
        {
            step+=x;
            if(y-x>k)
            {
                step+=k;
                step+=(((y-x)-k)*2);
                cout<<step<<endl;
            }
            else
            {
                step+=(y-x);
                cout<<step<<endl;
            }
        }
        else
        {
            step+=x;
            cout<<step<<endl;
        }
    }
    return 0;
}