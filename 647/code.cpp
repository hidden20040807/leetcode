#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int ans=0;
        for(int j=0;j<n;j++){
            for(int i=j;i>=0;i--){
                bool f=false;
                if(i+1>j-1){
                    f=true;
                }
                else if(dp[i+1][j-1]){
                    f=true;
                }
                if(f){
                    if(s[i]==s[j]){
                        ans++;
                        dp[i][j]=true;
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}