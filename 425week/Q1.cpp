#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT32_MAX;
        for(int k=l;k<=r;k++){
            int minnum=0;
            for(int i=0;i<k;i++){
                minnum+=nums[i];
            }
            if(minnum>0)
            ans=min(ans,minnum);
            int i=0;
            while(i+k<nums.size()){
                if(minnum>0){
                ans=min(ans,minnum);
                }
                minnum+=nums[i+k];
                minnum-=nums[i];
                i++;
            }
        }
        return ans==INT32_MAX?-1:ans;
    }
};
int main(){
    return 0;
}