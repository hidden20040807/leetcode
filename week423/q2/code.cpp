#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>pre(vector<int>& nums){
        vector<int>ans(nums.size(),1);
        int left=0;
        int right=1;
        while(right<nums.size()){
            while(right<nums.size()&&nums[right]>nums[right-1]){
                right++;
            }
            
            while(left<right){
                ans[left]=right-left;
                left++;
            }
            right=left+1;
        }
        
        return ans;
        
    }
    bool hasIncreasingSubarrays( int k,vector<int>& prv) {
        if(k==1)
        return true;
        for(int i=0;i<=prv.size()-2*k;i++){
            if(prv[i]>=k&&prv[i+k]>=k){
                return true;
            }
        }
        return false;

    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int>p=pre(nums);
        int left=1;
        int right=nums.size()/2;
        while(left<right){
            int mid=(left+right+1)>>1;
            if(hasIncreasingSubarrays(mid,p)){
                left=mid;
            }
            else{
                right=mid-1;
            }
        }
        return left;
        
        
    }
};
int main(){
    Solution s;
    vector<int>num{5,8,-2,-1};
    cout<<s.maxIncreasingSubarrays(num);
    return 0;
}