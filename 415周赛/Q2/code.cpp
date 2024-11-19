#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>>dp(b.size()+1,vector<long long>(5));
       dp[0][0]=0;
       //要注意边界的设定j==0 dp[i][j]=0,i==0 dp[i][j]选一个娶不到的值
        for (int j = 1; j < 5; j++) {
            dp[0][j] = LLONG_MIN / 2;
        }
        for(int i=1;i<=b.size();i++){
            int num=b[i-1];
            for(int j=1;j<=4;j++){
                
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+(long long)num*a[j-1]);
            }
        }
       return dp[b.size()][4];
       
    }
};
int main(){
    return 0;
}