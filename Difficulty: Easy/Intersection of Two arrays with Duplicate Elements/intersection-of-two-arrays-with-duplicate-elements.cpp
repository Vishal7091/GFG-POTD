//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        
          vector<int> ans;
         int i = 0, j = 0;
         int n = a.size(), m = b.size();

        // Sorting both arrays to efficiently find common elements
         sort(a.begin(), a.end());
         sort(b.begin(), b.end());

         // Traverse both arrays to find the common elements
         while (i < n && j < m) {
                if (a[i] == b[j]) {
                // Add element to the answer if it's not already added
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                // Move both pointers forward when a match is found
                i++;
                j++;
            } 
            else if (a[i] < b[j]) {
                // If element in a is smaller, move pointer in a forward
                i++;
            } 
            else {
                // If element in b is smaller, move pointer in b forward
                j++;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends