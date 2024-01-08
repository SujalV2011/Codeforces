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
        long long x,sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
        }    
        double sqr = sqrt(sum);
        if (sqr == int(sqr))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}