#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,counta=0,countd=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
        {
            counta++;
        }
        else
        {
            countd++;
        }
    }
    if(counta>countd)
    {
        cout<<"Anton";
    }
    else if(countd>counta)
    {
        cout<<"Danik";
    }
    else
    {
        cout<<"Friendship";
    }
}