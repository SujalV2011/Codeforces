#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum1=0,sum2=0;
        cin>>n;
        int arr;
        for(int i=0;i<n;i++)
        {
            cin>>arr;
            if(i<n/2)
                sum1+=arr;
            else
                sum2+=arr;
        }
        if(abs(sum1-sum2)%2==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}