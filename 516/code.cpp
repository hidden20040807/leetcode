#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            for(int i=j;i>=0;i--){
                int val=0;
                if(s[i]==s[j]){
                    if(i==j)
                    val=-1;
                    else if(i+1==j)
                    val=0;
                    else
                    val=dp[i+1][j-1];
                    val+=2;
                }
                if(i+1<=j){
                     dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                     dp[i][j]=max(dp[i][j],val);
                }
                else{
                    dp[i][j]=1;
                }                
            }
        }
        return dp[0][n-1];
    }
};
int main(){
    return 0;
}