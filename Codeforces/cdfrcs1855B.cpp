#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        int first=1,last=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
                last=i;
            else 
                break;
        }
        cout<<(last-first)+1<<endl;
    }
    return 0;
}