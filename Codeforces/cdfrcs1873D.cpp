#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int  main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int count=0;
        for(int i=0;i<n;)
        {
            if(s[i]=='B')
            {
                i=min(n,i+k);
                count++;
            }
            else
                i++;
        }
        cout<<count<<endl;
    }
}