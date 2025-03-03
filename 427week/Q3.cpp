#include<bits\stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
           vector<ll>pre(n+1,0);
           ll sum=0;
           for(int i=1;i<=n;i++){
                sum+=nums[i-1];
                pre[i]=sum;
           }
           vector<ll>minnum(n+1,INT64_MAX);
           ll ans=INT64_MIN;
           for(int i=0;i<=n;i++){
                if(minnum[i%k]!=INT64_MAX){
                    ans=max(ans,pre[i]-minnum[i%k]);
                }
                minnum[i%k]=min(minnum[i%k],pre[i]);
           }
           return ans;

    }
};
int main(){
    return 0;
}