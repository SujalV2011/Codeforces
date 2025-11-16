#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,x;
        cin>>n>>k>>x;

        vector<ll> a(n);
        for(ll i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());

        priority_queue<tuple<int,int,int,bool>> pq;
        if(a[0]!=0)
        {
            pq.push({a[0],-1,a[0],true});
        }

        for(ll i=0;i<n-1;i++)
        {
            pq.push({(a[i+1]-a[i])-1,a[i],a[i+1],false});
        }

        if(a[n-1]!=x)
        {
            pq.push({x - a[n-1],a[n-1],-1,true});
        }

        set<ll>ans;
        int temp=k;
        while(temp!=0)
        {
            auto [len,l,r,notfriend]=pq.top();
            pq.pop();
            if(len<=0)
                break;
            if(l==-1 || r==-1)
            {
                if(l==-1)
                {
                    ans.insert(l+1);
                    l+=1;
                    // cout<<"l: "<<l;
                    // cout<<endl;
                    if(r - l-1>0)
                    {
                        pq.push({r - l-1,l,r,true});
                        // cout<<"pushed: "<<r - l-1<<" "<<l<<" "<<r<<endl;
                    }
                    temp--;
                }
                else if(r==-1)
                {
                    ans.insert(x);
                    r=x;
                    // cout<<"r: "<<x;
                    // cout<<endl;
                    if(len-1>0)
                    {
                        pq.push({len-1,l,r,true});
                        // cout<<"pushed: "<<len-1<<" "<<l<<" "<<r<<endl;
                    }
                    temp--;
                }

                continue;
            }
            if(notfriend)
            {
                if(l<=a[0])
                {
                    ans.insert(l+1);
                    l+=1;
                    // cout<<"l: "<<l;
                    // cout<<endl;
                    if(r - l-1>0)
                    {
                        pq.push({r - l-1,l,r,true});
                        //cout<<"pushed: "<<r - l-1<<" "<<l<<" "<<r<<endl;
                    }
                    temp--;
                }
                else if(r>=a[n-1])
                {
                    ans.insert(r-1);
                    r-=1;
                    // cout<<"r: "<<r-1;
                    // cout<<endl;
                    if(len-1>0)
                    {
                        pq.push({len-1,l,r,true});
                        // cout<<"pushed: "<<len-1<<" "<<l<<" "<<r<<endl;
                    }
                    temp--;
                }
                continue;
            }
            ll mid=(l+r)/2;
            ans.insert(mid);
            if(mid - l - 1>0)
                pq.push({mid - l - 1,l,mid,false});
            if(r - mid - 1>0)
                pq.push({r - mid - 1,mid,r,false});
            temp--;
        }

        if(ans.size()<k)
        {
            for(int i=0;i<n;i++)
            {
                if(ans.size()>=k)
                    break;
                if(ans.find(a[i])==ans.end())
                {
                    ans.insert(a[i]);
                }
            }
        }

        for(auto it:ans)
            cout<<it<<" ";

        cout<<endl;
    }
}