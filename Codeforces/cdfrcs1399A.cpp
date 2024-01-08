#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        bool flag=true;
        for(int i=0;i<n-1;i++)
        {
            if(a[i+1]-a[i]>1)
            {
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
    }
    return 0;
}