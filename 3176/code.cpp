#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(nums.size(),vector<int>(k+1,0));
        int ret=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<=k;j++){
                int ans=1;
                for(int t=0;t<i;t++){
                    if(nums[i]==nums[t]){
                        ans=max(ans,dp[t][j]+1);
                    }
                    else if(j>=1){
                        ans=max(ans,dp[t][j-1]+1);
                    }
                }
                dp[i][j]=ans;
                ret=max(ans,ret);                
            }
        }
        return ret;
    }
};

int main(){
    vector<int>v{29,29,28};
    Solution s;
    cout<<s.maximumLength(v,0);
    return 0;
}