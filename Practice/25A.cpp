#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    int even=0,odd=0,evidx=-1,oddidx=-1;

    for(int i=0;i<n;i++)
    {
        if(a[i]&1)
        {
            odd++;
            oddidx=i;
        }
        else
        {
            even++;
            evidx=i;
        }
    }

    if(even==n-1)
    {
        cout<<oddidx+1<<endl;
    }
    else
    {
        cout<<evidx+1<<endl;
    }
}