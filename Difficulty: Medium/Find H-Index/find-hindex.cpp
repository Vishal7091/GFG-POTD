//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
   public:
    // Function to find hIndex
    int hIndex(vector<int>&arr) {
        // code here
       int n=arr.size();
        vector<int>fre(n+1,0);
        for(int &i:arr){// filling the frequency leve
            if(i>=n)fre[n]++; //O(n)
            else fre[i]++;
 
                           }
int h =n;
int sum=0;
int ans=INT_MIN;

for(int i=n;i>=0;i--){//O(n)

if(sum+fre[i]>=i)ans=max(ans,i);
sum+=fre[i];

}

return ans;
//time O(n)+O(n);
// space O(n)

       
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends