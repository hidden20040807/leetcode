#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
            vector<unsigned long long>dp(target+1,0);
            dp[0]=1;
            for(int j=1;j<=target;j++){
                for(int num:nums){
                    if(j-num>=0)
                    dp[j]+=dp[j-num];
                }
            }
            return dp[target];      
    }
    
};
int main(){
    return 0;
}