#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        s[n - 2] = 'i';
        for(int i=0;i<n-1;i++) 
        {
            cout << s[i];
        }
        cout << endl;
    }
    
    return 0;
}