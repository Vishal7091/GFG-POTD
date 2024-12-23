//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // Function to search a given number in row-column sorted matrix.
 bool searchMatrix(vector<vector<int>> &mat, int x) {
    // Check if the matrix is empty
    if (mat.empty()) return false;

    for (int i = 0; i < mat.size(); i++) {
        // Check if the current row is empty
        if (mat[i].empty()) continue;

        // Check if `x` could be in the current row
        if (mat[i][0] <= x && mat[i].back() >= x) {
            // Search in this row
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == x) {
                    return true;
                }
            }
            break; // No need to check further rows
        }
    }
    return false;
}


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends