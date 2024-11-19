#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int dp[100001][2][3];
     int checkRecord(int n) {
        dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
           for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                 dp[i][j][0]+=(dp[i-1][j][k])%mod;
                dp[i][j][0]%=mod;
            }
           }

           for(int j=0;j<2;j++){
            for(int k=1;k<3;k++){
                dp[i][j][k]+=(dp[i-1][j][k-1])%mod;
                dp[i][j][k]%=mod;
            }
            }

           for(int k=0;k<3;k++){
            dp[i][1][0]+=(dp[i-1][0][k])%mod;
            dp[i][1][0]%=mod;
           }
        }
        int ans=0;
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                ans+=dp[n][j][k];
                ans%=mod;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.checkRecord(10);
}