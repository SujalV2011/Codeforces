#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long a[4];
    int count=0;
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    for(int i=0;i<3;i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
        }
    }
    cout<<count;
    return 0;
}