//4x +2y =n

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
        int x=0;
        int cnt=0;
        while(x<=n)
        {
            int rem=n-4*x;
            if(rem>=0 && rem%2==0)
            {
                cnt++;
            }
            x++;
        }
        cout<<cnt<<endl;
    }    
}