#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int&n,int &k,vector<int>path,int maxi){
        if(path.size()==k){
            vector<int>v;
           for(int n:path){
            v.push_back(n);
           }
            ans.push_back(v);
            return;
        }
        //这里要剪枝
        for(int i=maxi+1;i<=n-k+1+path.size();i++){
          
           path.push_back(i);
           dfs(n,k,path,i);
         
           path.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>path;
        
        dfs(n,k,path,0);
        return ans;    
    }
};
int main(){
    return 0;
}