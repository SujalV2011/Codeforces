#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        int cnt=0;
        bool flg=true;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cnt++;
            }
            else
            {
                if(cnt>=k)
                {
                    flg=false;
                    break;
                }
                else
                {
                    cnt=0;
                }
            }
        }

        if(cnt>=k) flg=false;

        if(!flg) cout<<"NO"<<endl;
        else 
        {
            vector<int>arr(n,0);
            cout<<"YES"<<endl;
            int x=1;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1')
                {
                    arr[i]=x;
                    x++;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(s[i]!='1')
                {
                    arr[i]=x;
                    x++;
                }
            }
            for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}