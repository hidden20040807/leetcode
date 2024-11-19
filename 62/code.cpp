#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        dp[0][0]=1;
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(i==0&&j==0)
               continue;
              sum=0;
               if(i-1>=0)
                sum+=dp[i-1][j];
                if(j-1>=0)
                sum+=dp[i][j-1];
                dp[i][j]=sum;
            }
        }
        return dp[m-1][n-1];

    }
};
int main(){
    return 0;
}