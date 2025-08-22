#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a;
        string sa;
        cin>>sa;
        cin>>b;
        string sb;
        cin>>sb;
        string x;
        cin>>x;

        string res="";

        for(int i=x.size()-1;i>=0;i--)
        {
            if(x[i]=='V')
            {
                res+=sb[i];
            }
        }

        res+=sa;

        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='D')
            {
                res+=sb[i];
            }
        }

        cout<<res<<endl;
    }
}