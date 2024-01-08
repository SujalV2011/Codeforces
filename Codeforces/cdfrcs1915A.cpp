#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b==c)
            cout<<a<<endl;
        else if(a==c)
            cout<<b<<endl;
        else
            cout<<c<<endl;
    }
    return 0;
}