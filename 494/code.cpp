#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        if((sum+target)%2||(sum+target)<0)
        return 0;
        int pos=(sum+target)/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(pos+1,0));
        dp[0][0]=1;
        for(int i=1;i<=nums.size();i++){
            int num=nums[i-1];
            for(int j=0;j<=pos;j++){
               dp[i][j]=dp[i-1][j]; 
                if(j-num>=0)
                dp[i][j]+=dp[i-1][j-num];
               
            }
        }
        return dp[nums.size()][pos];
    }
};
signed main(){
    Solution s;
    vector<int>v{1,1,1,1,1};
    cout<<s.findTargetSumWays(v,3);
    return 0;
}