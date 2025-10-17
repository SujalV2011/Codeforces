#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;

        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }

        int x=a^b;

        if(x<=a)
        {
            cout<<1<<endl<<x<<endl;
            continue;
        }

        int msb=31-__builtin_clz(a);
        int m=(1<<(msb+1))-1;

        int x1=a^m;
        int x2=m^b;

        if(x1<=a && x2<=m)
        {
            cout<<2<<endl<<x1<<" "<<x2<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
}
