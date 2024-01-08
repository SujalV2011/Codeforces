#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,res;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int k=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='a' && s[i]!='o' && s[i]!='y' && s[i]!='e' && s[i]!='u' && s[i]!='i')
        {
            res.push_back(s[i]);
            res.insert(k,".");
            k+=2;
        }
    }
    cout<<res;
    return 0;
}