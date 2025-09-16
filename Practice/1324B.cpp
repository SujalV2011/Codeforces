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
        vector<int>a(n);

        for(int i=0;i<n;i++)    cin>>a[i];

        bool ok=false;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]==a[j] && (j-i)>1)
                {
                    ok=true;
                    break;
                }
            }
            if(ok)    break;
        }

        if(ok)    cout<<"YES\n";
        else      cout<<"NO\n";
    }
}