#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int dp[5001][4][3];
    int dir[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
    int mod=1e9+7;
    int knightDialer(int n) {
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(!((i==3&&j==0)||(i==3&&j==2)))
                dp[1][i][j]=1;
            }
        }
        for(int k=2;k<=n;k++){
            for(int i=0;i<4;i++){
                for(int j=0;j<3;j++){
                    if(!((i==3&&j==0)||(i==3&&j==2))){
                        int num=0;
                        for(int d=0;d<8;d++){
                            int x=i+dir[d][0];
                            int y=j+dir[d][1];
                            if(x>=0&&x<4&&y>=0&&y<3){
                                num=(num+dp[k-1][x][y])%mod;
                            }
                        }
                        dp[k][i][j]=num;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(!((i==3&&j==0)||(i==3&&j==2)))
                ans=(ans+dp[n][i][j])%mod;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    s.knightDialer(2);

    return 0;
}