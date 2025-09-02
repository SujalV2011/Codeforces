#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Observations:

    here the condition is that all subarray of lengt >= 2 the elemnts at odd postion in the original array not in the sub array and the elemnts at even pos the sum of even pos must be > than odd pos sum
    so we can try to make the sum of even pos > sump of odd pos bu checkinf=g the array of lengt 2 
    start with idx 1 chek if the curr elemnt is > than prev elemnt 
    if yes then we check the next elemt if its grater than check the subarray of 3 if all this condition full dfilss then move to next even idx and also take note of the sums of even po and odd pos

*/

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        ll evesum=0,oddsum=0;
        ll cnt=0;

        for(int i=1;i<n;i+=2)
        {
            
            if(a[i-1]>a[i])
            {
                cnt+=(a[i-1]-a[i]);
                a[i-1]=a[i];
            }
            if(i+1<n && a[i+1]>a[i])
            {
                cnt+=(a[i+1]-a[i]);
                a[i+1]=a[i];
            }
            if(i+1<n)
            {
                if(a[i]<a[i-1]+a[i+1])
                {
                    ll diff=(a[i-1]+a[i+1]-a[i]);
                    cnt+=diff;
                    if(a[i+1]>=diff)
                    {
                        a[i+1]-=diff;
                    }
                    else
                    {
                        a[i-1]-=diff;
                    }
                }
            }
            evesum+=a[i];
            oddsum+=a[i-1];
            if(i+1<n) oddsum+=a[i+1];

            if(evesum<oddsum)
            {
                ll diff=oddsum-evesum;
                if(i+1<n && a[i+1]>=diff)
                {
                    a[i+1]-=diff;
                }
                else
                {
                    
                    a[i-1]-=diff;
                }
                cnt+=diff;
                oddsum-=diff;
            }
        }
        cout<<cnt<<endl;
    }
}