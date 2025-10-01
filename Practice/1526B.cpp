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
        bool ok=false;
        for(int x=0;x<20;x++)
        {
            if(n%11==0)
            {
                ok=true;
                break;
            }
            n-=111;
            if(n<0) break;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
