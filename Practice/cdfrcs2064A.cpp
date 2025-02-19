#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string temp="";
        temp+=s[0];
        for(int i=1,j=0;i<n;i++)
        {
            if(s[i]!=temp[j])
            {
                temp+=s[i];
                j++;
            }
        }
        if(temp.size()==1)
        {
            if(temp[0]=='1')
                cout<<1<<endl;
            else
                cout<<0<<endl;
            
            continue;    
        }
        int cnt=0;
        
        for(int i=temp.size()-2;i>=0;i--)
        {
            if(temp[i]=='1')
                cnt+=2;
        }
        
        if(temp[temp.size()-1]=='1')
            cnt+=1;
            
        cout<<cnt<<endl;    
        
        
    }
}