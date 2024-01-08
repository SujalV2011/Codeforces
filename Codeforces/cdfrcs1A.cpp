#include<iostream>
using namespace std;
int main()
{
    long long int n,m,a,req;
    cin>>n>>m>>a;
    req=((n+a-1)/a)*((m+a-1)/a);
    cout<<req;
    return 0;
}