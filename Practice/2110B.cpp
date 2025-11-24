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
        int cnt=0;
        int x=0;

        for(int i=0;i<s.size();i++)
        {
            x+=(s[i]=='(');
            x-=(s[i]==')');
            if(x==0)
                cnt++;
        }

        if(cnt>1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}