#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int dp[101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {   
        vector<pair<int,int>>nums;
        for(string s:strs){
            int num0=0;
            int num1=0;
            for(char ch:s){
                if(ch=='0')
                num0++;
                else
                num1++;
            }
            nums.push_back({num0,num1});
        }
        for(pair<int,int>p:nums){
            for(int j=m;j>=0;j--){
                for(int k=n;k>=0;k--){
                    int val=0;
                    if(j-p.first>=0&&k-p.second>=0){
                        val=dp[j-p.first][k-p.second]+1;
                    }
                    dp[j][k]=max(dp[j][k],val);
                }
            }
        }
        return dp[m][n];

    }
};
unsigned main(){
    return 0;
}