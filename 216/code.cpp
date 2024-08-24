#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
     vector<vector<int>>ans;
     void dfs(int &k,int &n,vector<int>&path,int len,int min,int sum){
        if(sum>n)
        return;
        if(len==k){
            if(sum==n)
            ans.push_back(path);
            return;
        }
        for(int i=min+1;i<10;i++){
            path.push_back(i);
            dfs(k,n,path,len+1,i,sum+i);
            path.pop_back();
        }

     }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        dfs(k,n,path,0,0,0);
        return ans;
    }
};
int main(){
    return 0;
}