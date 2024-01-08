#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,count=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(a==i)
                count++;
        }
        if(count%2==0)
            cout<<count/2<<endl;
        else
            cout<<(count/2)+1<<endl;
    }
    return 0;
}