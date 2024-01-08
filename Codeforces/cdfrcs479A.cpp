#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int m1,m2,m3;
    m1=max((a+(b*c)),(a*(b+c)));
    m2=max((a*b*c),((a+b)*c));
    m3=max(((a*b)+c),(a+b+c));
    cout<<max(m1,max(m3,m2));
    return 0;
}