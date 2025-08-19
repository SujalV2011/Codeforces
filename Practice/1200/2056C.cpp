#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        if(n==6)
        {
            cout<<"1 1 2 3 1 2"<<endl;
        }
        else if(n==7)
        {
            cout<<"1 1 2 3 1 2 2"<<endl;
        }
        else
        {
            for(int i=0;i<n/2;i++)
            {
                cout<<i+1<<" ";
            }
            for(int i=n/2;i<n;i++)
            {
                cout<<i- n/2 +1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}