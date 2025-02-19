#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t-- > 0) {
        string str, ans = "";
        cin >> str;
        
        for (size_t i = 0; i < str.length() - 1; i++) {
            if (str[i] == 'u' && str[i + 1] == 's') {
                ans += 'i';
                break;
            }
            ans += str[i];
        }
        cout << ans << endl;
    }
    
    return 0;
}
