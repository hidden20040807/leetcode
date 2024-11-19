#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for(int j=0;j<grid[0].size();j++){
            for(int i=1;i<grid.size();i++){
                if(grid[i][j]!=grid[i-1][j]){
                    return false;
                }
            }
        }
        for(int j=0;j<grid[0].size()-1;j++){
            if(grid[0][j]==grid[0][j+1])
            return false;
        }
        return true;

    }
};
int main(){
    return 0;
}