#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
    Observation:

    -> here the main idea is that maximum index wecan reach such that it cover the maximum element in the array
    -> we can do this by maintaining two arrays one is bigPrefix and other is smallSuffix
    -> bigPrefix[i] will store the maximum element from 0 to i
    -> smallSuffix[i] will store the minimum element from i to n-1
    -> now we will traverse the array from right to left and check if bigPrefix[i] > smallSuffix[i+1] then we can reach the end from i
            -> if we can reach the end from i then we will update res[i] = res
            -> else we will update res[i] = bigPrefix[i]
    -> finally we will print the res array
*/

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> nums(n);

        for(int i=0;i<n;i++)    cin>>nums[i];

        vector<int> bigPrefix(n), smallSuffix(n);
        bigPrefix[0] = nums[0];
        smallSuffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) 
        {
            bigPrefix[i] = max(nums[i], bigPrefix[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) 
        {
            smallSuffix[i] = min(nums[i], smallSuffix[i + 1]);
        }

        vector<int> res(n, bigPrefix[n - 1]);
        for (int i = n - 2; i >= 0; i--) 
        {
            if (bigPrefix[i] > smallSuffix[i + 1]) 
            {
                res[i] = res[i + 1];
            } 
            else 
            {
                res[i] = bigPrefix[i];
            }
        }

        for (int i = 0; i < n; i++) 
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
