#include<iostream>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    string s;
    
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s.push_back(c); 
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            count++;
        }
    }
    
    cout << count;
    return 0;
}