#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(n%m==0)
        cout<<min((a*n),((n/m)*b));
    else
        cout<<min((((n/m)+1)*b),(((n/m)*b)+a*(n%m)));
    return 0;    
}