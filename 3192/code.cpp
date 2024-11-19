#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(2,0);
        for(int i=n-1;i>=0;i--){
            if(nums[i]){
                 dp[0]=dp[1]+1;
                 
            }
            else{
              
                dp[1]=dp[0]+1;
            }
        }
        return dp[1];
    }
};
int main(){
    return 0;
}