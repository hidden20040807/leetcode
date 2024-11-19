#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
           for(string str:wordDict){
                int n=str.size();
                if(!dp[i]&&i-n>=0&&str==s.substr(i-n,n)&&dp[i-n]){
                    dp[i]=true;
                }
            } 
        }
        return dp[s.size()];
    }
};
int main(){
    Solution s;
    string str="leetcode";
   
   vector<string>v{"leet","code"};
    s.wordBreak(str,v);
    return 0;
}