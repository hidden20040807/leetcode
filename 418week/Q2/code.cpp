#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>&v,vector<bool>&flag,int k){
            if(flag[k])
            return;
            flag[k]=true;
            for(int n:v[k]){
                dfs(v,flag,n);
            }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>tree(n);
        for(vector<int>g:invocations){
            tree[g[0]].push_back(g[1]);
        }
        vector<bool>flag(n,false);
        dfs(tree,flag,k);
        bool f=false;
       
        for(vector<int>v:invocations){
            if(!flag[v[0]]&&flag[v[1]]){
               f=true;
            }
        }
        if(f){
            vector<int>v;
            for(int i=0;i<n;i++){
                v.push_back(i);
            }
            return v;
        }
        else{
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(!flag[i])
                ans.push_back(i);
            }
            return ans;
        }
        
    }
       
};
int main(){
    vector<vector<int>>v{{1,2},{0,1},{2,0}};
    Solution s;
    s.remainingMethods(3,2,v);

    return 0;
}