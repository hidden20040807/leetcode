#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
//难度主要在于去重，首先要排序，这样重复主要来源于选择同一高度的节点选到重复的数字（同一个父节点），接下用哈希表去重 
    vector<vector<int>>ans;
    void dfs(vector<int>&nums,vector<int>&path,int i){
           ans.push_back(path);
           vector<bool>hash(21,false);
        for(int k=i+1;k<nums.size();k++){
            if(!hash[nums[k]+10]){
            hash[nums[k]+10]=true;
            path.push_back(nums[k]);
            dfs(nums,path,k);
            path.pop_back();
            }
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>path;
        sort(nums.begin(),nums.end());
        dfs(nums,path,-1);
        return ans;
    }
};
int main(){
    return 0;
}