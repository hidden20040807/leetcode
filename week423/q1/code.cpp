#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1)
        return true;
        for(int i=0;i<=nums.size()-2*k;i++){
            bool f1=true;
            for(int j=i;j<i+k-1;j++){
                if(nums[j]>=nums[j+1]){
                    f1=false;
                    break;
                }
            }
             for(int j=i+k;j<i+2*k-1;j++){
                if(nums[j]>=nums[j+1]){
                    f1=false;
                    break;
                }
            }
            if(f1){
                return f1;
            }
        }
        return false;

    }
};
int main(){
    Solution s;
    vector<int>n{2,5,7,8,9,2,3,4,3,1};
    cout<<s.hasIncreasingSubarrays(n,3);
    return 0;
}