#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a=0,i=0;
        vector<int>v;
        while(n>0)
        {
            if(n%10>0)
            {
                if(i==0)
                    v.push_back(n%10);
                else if(i==1)
                    v.push_back((n%10)*10);
                else if(i==2)
                    v.push_back((n%10)*100);
                else if(i==3)
                    v.push_back((n%10)*1000);
                else
                    v.push_back((n%10)*10000);
            }
            i++;
            n=n/10;
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;    
    }
    return 0;
}