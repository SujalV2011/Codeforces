#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        (abs(a-b)%10==0) ? cout<<abs(a-b)/10<<endl : cout<<(abs(a-b)/10)+1<<endl ;
    }
    return 0;
}