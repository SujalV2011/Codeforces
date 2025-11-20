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

        int a[n],b[n];

        int xor1=0,xor2=0;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            xor1^=a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            xor2^=b[i];
        }

        // cout<<xor1<<" "<<xor2<<endl;

        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                int x=(xor1^a[i])^b[i];
                int y=(xor2^b[i])^a[i];
                // cout<<"Before: "<<" "<<x<<" "<<y<<endl;
                if(x>=y)
                {
                    xor1=(xor1^a[i])^b[i];
                    xor2= (xor2^b[i])^a[i];
                }
                // cout<<"After: "<<" "<<xor1<<" "<<xor2<<endl;
            }
            else
            {
                int x=(xor2^b[i])^a[i];
                int y=(xor1^a[i])^b[i];
                // cout<<"Before: "<<" "<<x<<" "<<y<<endl;
                if(x>=y)
                {
                    xor2=(xor2^b[i])^a[i];
                    xor1=(xor1^a[i])^b[i];
                }
                // cout<<"After: "<<" "<<xor1<<" "<<xor2<<endl;
            }
        }

        if(xor1>xor2)
        {
            cout<<"Ajisai"<<endl;
        }
        else if(xor2>xor1)
        {
            cout<<"Mai"<<endl;
        }
        else
        {
            cout<<"Tie"<<endl;
        }
    }
}