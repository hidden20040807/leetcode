#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>((n+1)/2+1,0));
         int ans=0;
        for(int i=1;i<n;i++){
            int num=nums[i-1];
            for(int j=1;j<=(n+1)/2;j++){
               int val=0;
               if(i-2>=0)
               val=dp[i-2][j];
               dp[i][j]=max(dp[i-1][j],val+num);
               ans=max(ans,dp[i][j]);
            }
        }
        vector<vector<int>>dp2(n+1,vector<int>((n+1)/2+1,0));
        for(int i=2;i<=n;i++){
            int num=nums[i-1];
            for(int j=1;j<=(n+1)/2;j++){
               int val=0;
               if(i-2>=0)
               val=dp2[i-2][j];
               dp2[i][j]=max(dp2[i-1][j],val+num);
               ans=max(ans,dp2[i][j]);
            }
        }
        return ans;

    }
};
int main(){
    return 0;
}