#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
        
     
        int bestL = 0, bestR = 0;
        int bestDelta = 0; 
        
  
        for (int l = 0; l < n; l++)
        {
            int cntGreater = 0, cntLess = 0;
        
            for (int r = l + 1; r < n; r++)
            {
                if(a[r] > a[l])
                    cntGreater++;
                else if(a[r] < a[l])
                    cntLess++;
                    
                int delta = cntGreater - cntLess;
                if(delta < bestDelta)
                {
                    bestDelta = delta;
                    bestL = l;
                    bestR = r;
                }
            }
        }

    
        cout << bestL + 1 << " " << bestR + 1 << "\n";
    }
    return 0;
}