#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp{0,0,1};
        for(int i=3;i<=n;i++){
            int ans=-1;
            for(int j=1;j<i;j++){
                ans=max(ans,j*(i-j));
                ans=max(ans,j*dp[i-j]);
            }
            dp.push_back(ans);
        }
        return dp[n];
    }
};
int main(){
    return 0;
}