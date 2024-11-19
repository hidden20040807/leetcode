#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n=prizePositions.size();
        vector<int>dp(n+1,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            int num=prizePositions[i-1];
            int x=lower_bound(prizePositions.begin(),prizePositions.end(),num-k)-prizePositions.begin();
            ans=max(ans,dp[x-1]+i-x);
            dp[i]=max(dp[i-1],i-x);
            
        }
        return ans;
    
    }
};
int main(){
    vector<int>v{1,1,2,2,3,3,5};
    Solution s;
    s.maximizeWin(v,2);

    return 0;
}