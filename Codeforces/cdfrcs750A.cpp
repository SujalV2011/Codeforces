#include<iostream>
using namespace std;
int main()
{
    double n,k,time=0.0;
    int count=0;
    cin>>n>>k;
    time=k/60.0;
    int a[]={5,10,15,20,25,30,35,40,45,50};
    for(int i=0;i<n;i++)
    {
        time+=a[i]/60.0;
        if(4.0-time>=0)
            count++;
        else
            break;
    }
    cout<<count;
    return 0;
}