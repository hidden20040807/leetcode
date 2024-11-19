#include<bits\stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        int dp[n+1][m+1];
        rep(i,0,n+1){
            dp[i][0]=0;
        }
        rep(j,0,m+1){
            dp[0][j]=0;
        }
        rep(i,1,n+1){
            rep(j,1,m+1){
                if(nums1[i-1]==nums2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else
                dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
int  main(){
    return 0;
}