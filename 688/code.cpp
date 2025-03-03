#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int dir[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{1,-2},{2,-1}};
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>>dp(k+1,vector<vector<double>>(n,vector<double>(n,0)));
        dp[0][row][column]=1;
        for(int m=1;m<=k;m++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        double odd=0;
                        for(int d=0;d<8;d++){
                            int x=i+dir[d][0];
                            int y=j+dir[d][1];
                            if(x>=0&&x<n&&y>=0&&y<n){
                                odd+=dp[m-1][x][y]/8;
                            }
                        }
                        dp[m][i][j]=odd;
                }
            }
        }
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=dp[k][i][j];
            }
        }
        return ans;

    }
};
int main(){
    return 0;
}