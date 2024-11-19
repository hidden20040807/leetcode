#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int fa[1001];
    void init(){
        for(int i=0;i<=1000;i++){
            fa[i]=i;
        }
    }
    int find(int i){
        if(fa[i]==i)
        return i;
        fa[i]=find(fa[i]);
        return fa[i];
    }
    void join(int i,int j){
        int fi=find(i);
        int fj=find(j);
        fa[fj]=fi;
    }
    bool isTree(vector<vector<int>>& edges,int ig){
        init();
        for(int i=0;i<edges.size();i++){
            if(i!=ig){
                if(!(find(edges[i][0])==edges[i][1]))
                join(edges[i][0],edges[i][1]);
                else
                return false;
            }
        }
        return true;

    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
            vector<int>ru(1001,0);
            for(int i=0;i<edges.size();i++){
                ru[edges[i][1]]++;
            }
            int flag=0;
            for(int i=0;i<edges.size();i++){
                if(ru[edges[i][1]]==2){
                    flag=edges[i][1];
                }
            }
            if(flag){
                for(int i=edges.size()-1;i>=0;i--){
                    if(edges[i][1]==flag){
                        if(isTree(edges,i))
                        return edges[i];
                    }
                }
            }
            else{
                 for(int i=edges.size()-1;i>=0;i--){
                        if(isTree(edges,i))
                        return edges[i];
                }
            }
            return {};

    }
};
int main(){
    return 0;
}