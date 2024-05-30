//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    int swapNibbles(int n) {
        int res = 0;
        
        for (int i = 0; i < 4; i++) {
            if (n & (1 << i)) {
                res = res + (1 << (4 + i));
            }
        }
        
        for (int i = 4; i < 8; i++) {
            if (n & (1 << i)) {
                res = res + (1 << (i - 4));
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends