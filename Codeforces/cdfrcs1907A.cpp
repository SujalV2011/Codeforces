#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        for(int i=1;i<=8;i++)
        {
            if(i!=s[1]-48)
                cout<<s[0]<<i<<endl;
        }
        for(int i=0;i<8;i++)
        {
            if(char(97+i)!=s[0])
                cout<<char(97+i)<<s[1]<<endl;
        }
    }
    return 0;
}