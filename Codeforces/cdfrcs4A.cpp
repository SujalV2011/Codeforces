#include<iostream>
using namespace std;
int main()
{
    int w;
    cin>>w;
    if(w==2)
      cout<<"No";
    else if(w>=4 && w<=100 && w%2==0)
      cout<<"Yes";
    else 
      cout<<"No";    
    return 0;    
}