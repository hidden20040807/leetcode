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
        vector<bool>flag(51,false);
        for(int i=k+1;i<candidates.size();i++){
            if(!flag[candidates[i]]){
            flag[candidates[i]]=true;
            dfs(candidates,target,i,sum,path);
            }
        }
         path.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>path;
        sort(candidates.begin(),candidates.end());
         vector<bool>flag(51,false);
        for(int i=0;i<candidates.size();i++){
              if(!flag[candidates[i]]){
            flag[candidates[i]]=true;
            dfs(candidates,target,i,0,path);
            }
        }
       
        return ans;
    }
};
int main(){
    
    return 0;
}