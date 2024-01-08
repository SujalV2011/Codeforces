#include<bits/stdc++.h>
using namespace std;
int main()
{
    int zcount=0,ocount=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            zcount++;
            ocount=0;
        }
        else
        {
            ocount++;
            zcount=0;
        }
        if(ocount>6 || zcount>6)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}