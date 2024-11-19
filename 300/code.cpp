#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int ans=0;
        for(int i=1;i<n;i++){
            int Max=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    Max=max(Max,dp[j]);
                }
            }
            dp[i]=Max+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
int main(){
    return 0;
}