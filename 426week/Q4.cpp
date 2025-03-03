#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    void  dfs(vector<vector<int>>&tree,int i,int ahead,bool flag,int &ou,int &ji,vector<bool>&f){
        if(flag){
             ou++;
             f[i]=true;
        }
        else{
            ji++;
            f[i]=false; 
        }
       
        for(int j:tree[i]){
            if(j!=ahead){
                dfs(tree,j,i,!flag,ou,ji,f);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1=edges1.size()+1;
        int n2=edges2.size()+1;
        vector<vector<int>>tree1(n1);
        vector<vector<int>>tree2(n2);
        for(vector<int>v:edges1){
            tree1[v[0]].push_back(v[1]);
            tree1[v[1]].push_back(v[0]);
        }
        for(vector<int>v:edges2){
            tree2[v[0]].push_back(v[1]);
            tree2[v[1]].push_back(v[0]);
        }
        vector<int>num1(n1);
        vector<int>num2(n2);
        int max2=0;
        int ou=0;
        int ji=0;
        vector<bool>f1(n1);
        vector<bool>f2(n2);

        dfs(tree1,0,-1,true,ou,ji,f1);
        for(int i=0;i<n1;i++){
            if(f1[i])
            num1[i]=ou;
            else
            num1[i]=ji;
        }
        ou=0;
        ji=0;
        dfs(tree2,0,-1,true,ou,ji,f2);
        for(int i=0;i<n2;i++){
            if(f2[i])
            num2[i]=ji;
            else
            num2[i]=ou;
            max2=max(max2,num2[i]);
        }
        vector<int>ans(n1);
        for(int i=0;i<n1;i++){
            ans[i]=num1[i]+max2;
        }
        return ans;
        
    }
};
int main(){
    vector<vector<int>>v2={{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    vector<vector<int>>v1={{0,1},{0,2},{2,3},{2,4}};
    Solution s;
    s.maxTargetNodes(v1,v2);

    return 0;
}