#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int find(int i,vector<int>&fa){
        if(i==fa[i])
        return i;
        int n=find(fa[i],fa);
        fa[i]=n;
        return fa[i];
    }
    void uni(vector<int>&fa,int i,int j,int&ans){
        int fa_i=find(i,fa);
        int fa_j=find(j,fa);
        if(fa_j==fa_i)
        return ;
        fa[fa_i]=fa_j;
        ans--;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
            vector<int>fa(n);
            for(int i=0;i<n;i++){
                fa[i]=i;
            }
            vector<int>ret;
            int ans=n-1;
            for(vector<int>q:queries){
                for(int i=find(q[0],fa);i<q[1]-1;i=find(i,fa)){
                    uni(fa,i,i+1,ans);
                }
                ret.push_back(ans);
            }
            return ret;
    }
};
int main(){
    
    
    return 0;
}