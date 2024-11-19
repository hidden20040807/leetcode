#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
      int left=1;
      int right=nums.size()/2;
      sort(nums.begin(),nums.end());
      while(left<=right){
          int mid=(left+right)>>1;
          if(check(nums,mid)){
            left=mid+1;
          }
          else{
            right=mid-1;
          }
      }
      return 2*(left-1);
      
    
    }
    bool check(vector<int>&nums,int k){
        for(int i=0;i<k;i++){
          if(2*nums[i]>nums[nums.size()-k+i]){
            return false;
          }
        }
        return true;
    }
};
int main(){
    vector<int>v{9,2,5,4};
    Solution s;
    cout<<s.maxNumOfMarkedIndices(v);
    
    return 0;
}