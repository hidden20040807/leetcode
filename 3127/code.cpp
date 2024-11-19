#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                char color=grid[i][j];
                int B=0;
                int W=0;
                for(int a=i;a<i+2;a++){
                    for(int b=j;b<j+2;b++){
                        if(grid[a][b]=='B')
                        B++;
                        else
                        W++;
                    }
                }
                if(B>=3||W>=3)
                return true;
            }
        }
        return false;
    }
};
int main(){
    return 0;
}