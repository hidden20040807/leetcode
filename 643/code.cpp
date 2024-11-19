#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        int left=0;
        double sum=0;
        for(int i=left;i<left+k;i++){
            sum+=nums[i];
        }
        ans=max(ans,sum/k);
        while(left+k<nums.size()){
            sum+=nums[left+k];
            sum-=nums[left];
            left++;
            ans=max(ans,sum/k);
        }
        return ans;
    }
};
int main(){
    return 0;
}