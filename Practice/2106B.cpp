#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;

        vector<int>a;
        
        for(int i=0;i<n;i++)
        {
            if(i!=x)
            {
                a.push_back(i);
            }
        }

        if(a.size()!=n)
            a.push_back(x);
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}