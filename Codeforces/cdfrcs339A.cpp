#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    if(str.size()==1)
    {
        cout<<str;
        return 0;
    }
    for(int j=0;j<str.size();j++)
    {
        for(int i=0;i<str.size()-2;i+=2)
        {
            if((str[i]*1)>(str[i+2]*1))
            {
                swap(str[i],str[i+2]);
            } 
        }
    }
    cout<<str;
    return 0;
}