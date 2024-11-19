#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
      int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT32_MAX));
        deque<pair<int,int>>queue;
        if(grid[0][0]){
            dis[0][0]=1;
        }
        else{
            dis[0][0]=0;
        }
        queue.push_back({0,0});
        while(!queue.empty()){
            auto [x,y]=queue.front();
            queue.pop_front();
            for(auto&[i,j]:dir){
                int X=x+i;
                int Y=y+j;
                if(X>=0&&X<m&&Y>=0&&Y<n){
                    int cost=grid[X][Y];
                    if(dis[x][y]+cost<dis[X][Y]){
                        dis[X][Y]=dis[x][y]+cost;
                        cost==0?queue.push_front({X,Y}):queue.push_back({X,Y});
                    }
                }
            }
            
        }
        return dis[m-1][n-1]<health;
    }
};
int main(){
    return 0;
}