#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>((n+1)/2+1,0));
        for(int i=1;i<=n;i++){
            int num=nums[i-1];
            for(int j=1;j<=(n+1)/2;j++){
                int val=0;
                if(i-2>=0){
                    val=dp[i-2][j-1];
                }
                dp[i][j]=max(dp[i-1][j],val+num);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}