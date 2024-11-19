#include<bits/stdc++.h>
using namespace std;
class NeighborSum {
public:
    vector<vector<int>>v;
    int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    NeighborSum(vector<vector<int>>& grid) {
        v=grid;
    }
    
    int adjacentSum(int value) {
        int m=v.size();
        int n=v[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==value){
                    for(int k=0;k<4;k++){
                    if(dir[k][0]+i>=0&&dir[k][0]+i<m&&dir[k][1]+j>=0&&dir[k][1]+j<n){
                        ans+=v[dir[k][0]+i][dir[k][1]+j];
                    }
                    }
                }
                
            }
        }
        return ans;
    }
    int diagonalSum(int value) {
         int m=v.size();
        int n=v[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==value){
                    for(int k=4;k<8;k++){
                    if(dir[k][0]+i>=0&&dir[k][0]+i<m&&dir[k][1]+j>=0&&dir[k][1]+j<n){
                        ans+=v[dir[k][0]+i][dir[k][1]+j];
                    }
                    }
                }
                
            }
        }
        return ans;
    }
};


int main(){
    return 0;
}