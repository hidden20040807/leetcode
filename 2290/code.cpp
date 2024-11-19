#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        deque<pair<int,int>>q;
        vector<vector<int>>dis(m,vector<int>(n,INT32_MAX));
        dis[0][0]=grid[0][0];
        q.emplace_back(0,0);
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop_front();
            for(auto& [dx,dy]:dir){
                int x=i+dx;
                int y=j+dy;
                if(x>=0&&x<m&&y>=0&&y<n){
                    int cost=grid[x][y];
                    if(cost+dis[i][j]<dis[x][y]){
                        dis[x][y]=cost+dis[i][j];
                        cost?q.emplace_back(x,y):q.emplace_front(x,y);
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};
int main(){
    return 0;
}