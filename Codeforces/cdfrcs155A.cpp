#include<iostream>
using namespace std;
int main()
{
    int n,max,min,x,count=0;
    cin>>n;
    cin>>x;
    max=x;
    min=x;
    for(int i=1;i<n;i++)
    {
        cin>>x;
        if(x>max)
        {
            count++;
            max=x;
        }
        if(x<min)
        {
            count++;
            min=x;
        }
    }
    cout<<count;
    return 0;
}