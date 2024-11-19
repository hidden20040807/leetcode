#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1>n2)
        return false;
        vector<vector<bool>>dp(n2+1,vector<bool>(n1+1,false));
        for(int i=0;i<=n2;i++){
            dp[i][0]=true;
        }
        
        for(int i=1;i<=n2;i++){
            for(int j=1;j<=n1;j++){
                if(t[i-1]==s[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n2][n1];
    }
};
int main(){
    return 0;
}