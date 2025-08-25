#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
    Observation:

    -> here we can remove any two elemnt but the condition is that the after removal of that elemts the sum sum of the array must lie in the range of x, y
        ie. x <= sum of arr (after removing pair a[i], a[j]) <= y
        -> so here the order of the array is not required so the main idea is to sort the array
        -> now for index i we use binary search to find the index j such that the sum of the array after removing a[i] and a[j] lies in the range of x, y
            -> the index j must be greater than i and also all the form index j to n -1 must satisfy the condition
                -> so the number of pairs will be n - j
*/

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, x, y;
        cin>>n>>x>>y;
        vector<int> nums(n);
        ll totalSum = 0;

        for(int i=0;i<n;i++)    
        {
            cin>>nums[i];
            totalSum += nums[i];
        }

        sort(nums.begin(), nums.end());
        // cout<<endl;
        // for(int i=0;i<n;i++)    cout<<nums[i]<<" ";
        // cout<<endl;
        // cout<<"totalSum: "<<totalSum<<endl;
        // cout<<endl;

        ll count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ll low = i + 1, high = n - 1;
            ll leftIndex = -1, rightIndex = -1;

            // Binary search for the left index
            while (low <= high) 
            {
                ll mid = low + (high - low) / 2;
                ll currentSum = totalSum - nums[i] - nums[mid];

                if (currentSum >= x && currentSum <= y) 
                {
                    leftIndex = mid;
                    high = mid - 1;
                } 
                else if(currentSum > y) 
                {
                    low = mid + 1;
                } 
                else
                {
                    high = mid - 1;
                }
            }

            low = i + 1;
            high = n - 1;

            // Binary search for the right index
            while (low <= high) 
            {
                ll mid = low + (high - low) / 2;
                ll currentSum = totalSum - nums[i] - nums[mid];

                if (currentSum <= y && currentSum >= x) 
                {
                    rightIndex = mid;
                    low = mid + 1;
                } 
                else if(currentSum > y) 
                {
                    low = mid + 1;
                } 
                else
                {
                    high = mid - 1;
                }
            }
            // cout<<"i: "<<i<<" leftIndex: "<<leftIndex<<" rightIndex: "<<rightIndex<<endl;

            if (leftIndex!=-1 && rightIndex!=-1 && leftIndex <= rightIndex  && leftIndex > i) 
            {
                count += (rightIndex - leftIndex + 1);
            }
        }

        cout << count << endl;
    }
    return 0;
}