#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int k,vector<vector<int>>&tree,int i,int ahead){
        if(k<=0)
        return 1;
        int ans=1;
        for(int j:tree[i]){
            if(j!=ahead)
            ans+=dfs(k-1,tree,j,i);
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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
        for(int i=0;i<n1;i++){
            num1[i]=dfs(k,tree1,i,-1);
        }
        if(k>0){
        for(int i=0;i<n2;i++){
            num2[i]=dfs(k-1,tree2,i,-1);
            max2=max(max2,num2[i]);
        }
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
    s.maxTargetNodes(v1,v2,2);

    return 0;
}