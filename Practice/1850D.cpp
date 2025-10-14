#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);

        for(int i=0;i<n;i++) cin>>arr[i];   
        sort(arr.begin(),arr.end());

        int len=1;
        int maxlen=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]>k)   len=1;
            else    len++;
            maxlen=max(maxlen,len);
        }

        cout<<((n==1)? 0 : n-maxlen)<<endl;
    }
}