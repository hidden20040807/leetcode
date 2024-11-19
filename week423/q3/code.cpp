#include<bits\stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
     map<ll,ll>hash;
     map<ll,ll>count;
     int mod=1e9+7;
    int sumOfGoodSubsequences(vector<int>& nums) {
        vector<ll>dp(nums.size(),1);
        ll ans=0;
        for(int i=0;i<nums.size();i++){
            ll num=0;
            ll c=0;
            if(hash.count(nums[i]-1)){
                num+=hash[nums[i]-1]%mod;
                c=(c+count[nums[i]-1])%mod;
            }
            if(hash.count(nums[i]+1)){
                num+=hash[nums[i]+1]%mod;
                 c=(c+count[nums[i]+1])%mod;
            }
            dp[i]=(num+nums[i]+(nums[i]*c)%mod)%mod;
            if(!hash.count(nums[i])){
                 hash[nums[i]]=dp[i];
                 count[nums[i]]=(c+1)%mod;
            }
            else{
                 hash[nums[i]]=(dp[i]+hash[nums[i]])%mod;
                 count[nums[i]]+=(c+1)%mod;
            }
            ans=(dp[i]+ans)%mod;
        }
        return ans;
    }
};
int main(){
    vector<int>n{3,4,5};
    Solution s;
    cout<<s.sumOfGoodSubsequences(n);

    return 0;
}