#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x=0;
    string y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>y;
        if(y=="++X")
            ++x;
        else if(y=="X++")
            x++;
        else if(y=="--X")
            --x;
        else 
            x--;
        y="NULL";
    }
    cout<<x;
    return 0;
}