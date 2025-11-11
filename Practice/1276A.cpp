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
        int n=s.size();
        vector<int>idx;

        for(int i=0;i<n-2;i++)
        {
            if(i+4<n && s.substr(i,5)=="twone")
            {
                idx.push_back(i+3);
                i+=4;
            }
            else if(s.substr(i,3)=="one")
            {
                idx.push_back(i+2);
                i+=2;
            }
            else if(s.substr(i,3)=="two")
            {
                idx.push_back(i+2);
                i+=2;
            }
        }

        cout<<idx.size()<<endl;
        for(auto &i:idx)
            cout<<i<<" ";
        cout<<endl;
    }
}
