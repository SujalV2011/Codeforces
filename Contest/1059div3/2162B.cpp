#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s)
{
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r])return false;
        l++,r--;
    }
    return true;
}

bool isNonDecreasing(const string &s)
{
    for(int i=1;i<s.size();i++)
        if(s[i]<s[i-1])return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;

        bool found=false;

        for(int mask=0;mask<(1<<n);mask++)
        {
            string p="";
            vector<int>idx;

            for(int i=0;i<n;i++)
                if(mask&(1<<i))
                {
                    p+=s[i];
                    idx.push_back(i+1);
                }

            if(!isNonDecreasing(p))
                continue;

            string x="";
            for(int i=0;i<n;i++)
                if(!(mask&(1<<i)))
                    x+=s[i];

            if(isPalindrome(x))
            {
                cout<<idx.size()<<"\n";
                if(!idx.empty())
                {
                    for(int i=0;i<idx.size();i++)
                        cout<<idx[i]<<(i+1==idx.size()?'\n':' ');
                }
                else cout<<"\n";
                found=true;
                break;
            }
        }

        if(!found)
            cout<<"-1\n";
    }
}
