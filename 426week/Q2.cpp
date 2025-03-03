#include<bits\stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        ll sum=0;
        for(int n:nums){
            sum+=n;
        }
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            int exp=nums[i];
            ll sum1=sum-exp;
            int left=0;
            int right=nums.size()-1;
            int mid;
            while(left<=right){
                 mid=(left+right)>>1;
                if(nums[mid]==sum1-nums[mid]){
                    break;
                }
                else if(nums[mid]>sum1-nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            if(nums[mid]==sum1-nums[mid]&&mid!=i){
                return nums[i];
            }
        }
        return -1;
    }
};
int main(){
    return 0;
}