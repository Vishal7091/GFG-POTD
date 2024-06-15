//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  long long memo[4][3][1001];
    public:
    int isValid(int x, int y){
        if(x<0||x>=4||y<0||y>=3)
        {
            return 0;
        }
        if((x==3&&y==0)||(x==3&&y==2))
        return 0;
        return 1;
    }
    public:
    long long countWays(int x,int y,int n){
       if(n==1)
        return 1;
        if(memo[x][y][n]!=-1)
        return memo[x][y][n];
        
        long long totalCount=0;
        int moves[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<5;i++){
            int nextX=x+moves[i][0];
            int nextY=y+moves[i][1];
            if(isValid(nextX,nextY)){
                totalCount+=countWays(nextX,nextY,n-1);
            }
        }
        memo[x][y][n]=totalCount;
        return totalCount;
   
    }
  public:
 
    long long getCount(int n) {
        // Your code goes here
long long total=0;
      
      for(int i=0;i<4;i++)
      {
          for(int j=0;j<3;j++)
          {
              for(int k=0;k<=n;k++){
                  memo[i][j][k]=-1;
              }
          }
      }
      
      for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
              if(isValid(i,j)){
                  total+=countWays(i,j,n);
              }
          }
      }
      return total;
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends