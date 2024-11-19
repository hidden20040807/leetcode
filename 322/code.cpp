#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        dp[0]=0;
        for(int coin:coins){
            for(int i=1;i<=amount;i++){
                if(i-coin>=0){
                    if(dp[i]==-1){
                        if(dp[i-coin]!=-1)
                            dp[i]=dp[i-coin]+1;
                    }
                    else{
                        if(dp[i-coin]!=-1)
                        dp[i]=min(dp[i-coin]+1,dp[i]);
                    }
                }
            }
        }
        return dp[amount];
    }
};
int main(){
    Solution s;
    vector<int>v{1,2,5};
    cout<<s.coinChange(v,11);
    return 0;
}