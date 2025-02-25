#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,p;
        cin>>n>>k>>p;
        int x;
        if(k%p==0)
        {
            x=abs(k)/p;
        }
        else
            x=(abs(k)/p)+1;

        if(x<=n)
            cout<<abs(x)<<"\n";
        else
            cout<<-1<<"\n";    
    }
    return 0;
}