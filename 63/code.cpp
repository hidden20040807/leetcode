#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m=obstacleGrid.size();
            int n=obstacleGrid[0].size();
            int dp[m][n];
            dp[0][0]=1;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0&&j==0)
                    continue;
                    if(!obstacleGrid[i][j]){
                        int sum=0;
                    if(i-1>=0){
                        if(!obstacleGrid[i-1][j])
                        sum+=dp[i-1][j];
                    }
                    if(j-1>=0){
                        if(!obstacleGrid[i][j-1])
                        sum+=dp[i][j-1];
                    }
                    dp[i][j]=sum;
                    } 
                }
            }
            if(obstacleGrid[m-1][n-1])
            return 0;
            return dp[m-1][n-1];
    }
};
int main(){
   
    return 0;
}