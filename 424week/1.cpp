#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int check(vector<int>& nums,int i){
        int left=0;
        int right=0;
        for(int j=0;j<i;j++){
            left+=nums[j];
        }
         for(int j=i;j<nums.size();j++){
            right+=nums[j];
        }
        if(left==right){
            return 2;
        }
        else if(abs(left-right)==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    int countValidSelections(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans+=check(nums,i);
            }
        }
        return ans;
    }
};
int  main(){
    return 0;
}