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

        int diff=INT_MIN;

        sort(a.begin(),a.end());

        for(int i=0;i<n;i+=2)
        {
            diff=max(diff,a[i+1]-a[i]);
        }

        cout<<diff<<endl;
    }
}