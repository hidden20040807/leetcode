#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<int>& candidates,int &target,int k,int sum,vector<int>&path){
        sum+=candidates[k];
         path.push_back(candidates[k]);
        if(sum>target){
             path.pop_back();
            return;
        }
        if(sum==target){
            ans.push_back(path);
             path.pop_back();
            return;
        }
        for(int i=k;i<candidates.size();i++){
            dfs(candidates,target,i,sum,path);
            
        }
         path.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        for(int i=0;i<candidates.size();i++){
            dfs(candidates,target,i,0,path);
        }
       
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>v{2,3,6,7};

    s.combinationSum(v,7);
    return 0;
}