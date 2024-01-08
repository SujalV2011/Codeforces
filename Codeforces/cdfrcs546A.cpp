#include<iostream>
using namespace std;
int main()
{
    int k,n,w,amount=0;
    cin>>k>>n>>w;
    for(int i=1;i<=w;i++)
    {
        amount+=(i*k);
    }
    if(amount<=n)
    {
        cout<<"0";
    }
    else
    {
        cout<<amount-n;
    }
    return 0;
}