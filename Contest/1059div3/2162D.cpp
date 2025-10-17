#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) 
    {
        int n;
        cin >> n;
        
        cout << "1 1 " << n << endl;
        long long total_p;
        cin >> total_p;
        
        cout << "2 1 " << n << endl;
        long long total_a;
        cin >> total_a;
        
        int len = total_a - total_p;
        
        if (len == 0) 
        {
            cout << "! 1 1" << endl;
            continue;
        }
        
        int left = 1, right = n - len + 1, l = 1;
        while (left <= right) 
        {
            int mid = (left + right) / 2;
            cout << "1 1 " << mid << endl;
            long long sum_p;
            cin >> sum_p;
            cout << "2 1 " << mid << endl;
            long long sum_a;
            cin >> sum_a;
            
            if (sum_a > sum_p) 
            {
                l = mid;
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        
        cout << "! " << l << " " << l + len - 1 << endl;
    }
    
    return 0;
}