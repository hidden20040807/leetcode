#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        vector<int>nums(32,0);
        for(int num:candidates){
            for(int i=0;i<32;i++){
                nums[i]+=num>>i&1;
                ans=max(ans,nums[i]);
            }
        }
        return ans;
    }
};
int main(){
return 0;
}