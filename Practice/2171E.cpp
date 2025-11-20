#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> vec;
        vector<int> good,bad;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0) good.push_back(i); 
        }
        for(int i=1;i<=n;i++)
        {
            if(i%3==0&& i%2!=0) good.push_back(i); 
        }
        for(int i=1;i<=n;i++)
        {
            if(i%3!=0&& i%2!=0) bad.push_back(i); 
        }
        int a=0,b=0;
        for(int i=1;i<=n+10;i++)
        {
            if(i%3==0 && !bad.empty())
            {
                vec.push_back(bad.back());
                bad.pop_back();
            }
            else
            {
                if(good.empty()) continue;
                vec.push_back(good.back());
                good.pop_back();
            }
        }
        for(int x:vec) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}
