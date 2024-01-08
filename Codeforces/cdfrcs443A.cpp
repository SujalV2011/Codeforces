#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a;
    string s="";
    int count=0;
    while(1)
    {
        cin>>a;
        if((a*1)>=97 && (a*1)<=122)
            s+=a;
        if(a=='}')
            break;
    }
    if(s.size()<1)
    {
        cout<<count;
        return 0;
    }
    count=1;
    sort(s.begin(),s.end());
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1])
            count++;
    }
    cout<<count;
}