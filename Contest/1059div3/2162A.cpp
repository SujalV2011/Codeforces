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

        for(int i=0;i<n;i++)
            cin>>a[i];
        
        int mx=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=a[j];
                mx=max(mx,sum/(j-i+1));
            }
        }

        cout<<mx<<endl;
    }
}