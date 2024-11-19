#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int dp[n][2*k+1];
        for(int i=0;i<2*k+1;i++){
            if(i%2==0)
            dp[0][i]=0;
            else
            dp[0][i]=-prices[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<2*k+1;j++){
                if(j%2==0){
                    if(j==0)
                    dp[i][j]=dp[i-1][j];
                    else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+prices[i]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]-prices[i]);
                }
            }
        }
        return dp[n-1][2*k];
    }
};
int main(){
    return 0;
}