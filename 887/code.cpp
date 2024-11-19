#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
       for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
                int left=1;
                int right=i;
                 if(j==1){
                    dp[i][j]=i;
                    continue;
                }
                while(left+1<right){
                    int mid=(left+right)>>1;
                    if(dp[i-mid][j]==dp[mid-1][j-1]){
                        left=mid;
                        right=mid;
                        break;
                    }
                    else if(dp[i-mid][j]>dp[mid-1][j-1]){
                        left=mid+1;
                    }
                    else{
                        right=mid-1;
                    }
                }
                dp[i][j]=min(max(dp[i-left][j],dp[left-1][k-1]),max(dp[i-right][j],dp[right-1][j-1]))+1;

            }
        }
        return dp[n][k];
    }
};
int main(){
    Solution s;
    cout<<s.superEggDrop(3,7);
    return 0;
}