#include<bits/stdc++.h>
using namespace std;
using ll=long long;

/*
    Observations:

        here we need to divide the array into k subarrays such that each subarray has odd sum
        -> so it is obvious that if count of off numbers in the array is < k than its impossible
            -> now if the count of odd is > k then what to do?
            
            let k=3
            and array is 1 3 5 7 9
                -> here we can observa that we two odd numbers create a even sum now this can be used with another odd number to 
                    get our sondition stisfied

            now if k=4
            arr = [1 3 5 7 9 11 12]
                now here we can observe that we can take first 4 odd numbers and if the remaining count of oddnumberrs is even 
                    then the condition is satisfied'

                -> so the condition if cnt%2==k%2 then we can say that the condition is satisfied

*/

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++)    cin>>a[i];

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]&1)  cnt++;
        }

        if(cnt<k || cnt%2!=k%2)
        {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
        
        for(int i=0;i<n && k>1;i++)
        {
            if(a[i]&1)
            {
                cout<<i+1<<" ";
                k--;
            }
            
        }
        cout<<n<<endl;
    }
}