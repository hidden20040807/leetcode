#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()+2];
        dp[cost.size()]=0;
        dp[cost.size()+1]=0;
        for(int i=cost.size()-1;i>=0;i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};
int main(){
    return 0;
}