#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int cap=0;
        for(int n:stones){
            cap+=n;
        }
        int size=cap/2;
        vector<int>dp(size+1,0);
        for(int i=0;i<stones.size();i++){
            for(int j=size;j>0;j--){
                int val=0;
                if(j-stones[i]>=0){
                    val=dp[j-stones[i]]+stones[i];
                }
                dp[j]=max(dp[j],val);
            }
        }
        return cap-2*dp[size];
    }
};
int main(){
    return 0;
}