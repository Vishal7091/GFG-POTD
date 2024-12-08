//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSortAndCount(arr, temp, 0, n - 1);
    }

private:
    // Merge Sort function that returns the number of inversions
    int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            invCount += mergeSortAndCount(arr, temp, left, mid);         // Count inversions in left half
            invCount += mergeSortAndCount(arr, temp, mid + 1, right);    // Count inversions in right half

            invCount += mergeAndCount(arr, temp, left, mid, right);       // Count inversions during merge
        }
        return invCount;
    }

    // Merge function that merges two sorted subarrays and counts inversions
    int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        int invCount = 0;

        // Merge the two halves
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // There are mid - i inversions, because all the remaining elements in the left
                // subarray (arr[i], arr[i+1], ..., arr[mid]) are greater than arr[j]
                temp[k++] = arr[j++];
                invCount += (mid - i + 1);
            }
        }

        // Copy the remaining elements of left subarray, if any
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy the remaining elements of right subarray, if any
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the sorted subarray into original array
        for (int i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return invCount;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends