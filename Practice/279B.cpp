#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int mx=0;
    int sum=0;
    for(int r=0,l=0;r<n;r++)
    {
        sum+=arr[r];

        while(sum>t && l<=r)
            sum-=arr[l++];
        mx=max(mx,r-l+1);
    }

    cout<<mx<<endl;
    return 0;
}