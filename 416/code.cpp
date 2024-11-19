#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    //nums的每个数字既可以是价值也可以是重量，开一个容量为sum/2大小的背包即可，查看是否被装满即可
    bool canPartition(vector<int>& nums) {
        int cap=0;
       for(int n:nums){
        cap+=n;
       }
       if(cap%2)
       return false;
       vector<int>dp(cap/2+1,0);
        for(int i=0;i<nums.size();i++){
            for(int j=dp.size()-1;j>0;j--){
                int val=0;
                if(j-nums[i]>=0){
                    val=dp[j-nums[i]]+nums[i];
                }
                dp[j]=max(dp[j],val);
            }
        }
        if(dp[cap/2]==cap/2)
        return true;
        return false;
    }
};
int main(){
    vector<int>v{23,13,11,7,6,5,5};
    Solution s;
    cout<<s.canPartition(v);
    return 0;
}