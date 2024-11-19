#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int fa[1001];
    void init(){
        for(int i=0;i<1001;i++){
            fa[i]=i;
        }
    }
    int find(int i){
        if(i==fa[i])
        return i;
        fa[i]=find(fa[i]);
        return fa[i];
    }
    void uion(int i,int j){
        int fa_i=find(i);
        int fa_j=find(j);
        fa[fa_j]=fa_i;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(vector<int>v:edges){
            int i=v[0];
            int j=v[1];
            if(find(i)==find(j))
            return v;
            uion(i,j);
        }
        return edges[0];
    }
};
int main(){
    vector<vector<int>>edges={{1,2},{1,3},{2,3}};
    Solution s;
    s.findRedundantConnection(edges);
    return 0;
}