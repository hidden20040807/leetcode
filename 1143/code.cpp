#include<bits\stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
           
            int m=text1.size();
            int n=text2.size();
            int dp[m+1][n+1];
            rep(i,0,m){
                dp[i][0]=0;
            }
            rep(j,0,n){
                dp[0][j]=0;
            }
            rep(i,1,m+1){
                rep(j,1,n+1){
                   if(text1[i-1]==text2[j-1]){
                      dp[i][j]=dp[i-1][j-1]+1;
                      
                   }
                   else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);   
                   }
                }
               
            }
            return dp[m][n];

    }
};
int main(){
    Solution s;
    cout<<s.longestCommonSubsequence("abcba","abcbcba");
    return 0;
}