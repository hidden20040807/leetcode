#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<int>&nums,vector<int>&path,int i){
        ans.push_back(path);
        for(int k=i+1;k<nums.size();k++){
            path.push_back(nums[k]);
            dfs(nums,path,k);
            path.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        dfs(nums,path,-1);
        return ans;
    }
};
int main(){
    vector<int>v{1,2,3};
    Solution s;
    s.subsets(v);
    return 0;
}