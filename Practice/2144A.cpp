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
        int arr[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        bool flg=false;
        int s1=0;
        int s2=0;
        int l=0,r=0;
        for(int i=0;i<n-2;i++)
        {
            s1+=arr[i];
            for(int j=i+1;j<n-1;j++)
            {
                s2+=arr[j];

                if(s1%3==s2%3  && s2%3==(sum-s2-s1)%3)
                {
                    l=i+1,r=j+1;
                    flg=true;
                    break;
                }

                if(s1%3!=s2%3 && s2%3!=(sum-s2-s1)%3 && s1%3!=(sum-s2-s1)%3)
                {
                    l=i+1,r=j+1;
                    flg=true;
                    break;
                }
            }
            if(flg)
                break;
            s2=0;
        }

        if(!flg)
            cout<<"0 0"<<endl;
        else
            cout<<l<<" "<<r<<endl;
    }
    return 0;
}