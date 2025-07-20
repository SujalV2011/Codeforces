#include<bits/stdc++.h>
using namespace std;
bool help(int idx, vector<int>arr, int sum)
{
    if(idx>=arr.size())
    {
        if(sum%360==0)
        {
            return true;
        }
        return false;
    }

    return (help(idx+1,arr,sum+arr[idx]) || help(idx+1,arr,sum-arr[idx])); 
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    bool ok=help(0,arr,0);
    if(ok)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}