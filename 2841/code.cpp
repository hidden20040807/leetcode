#include<bits\stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        map<int,int>hash;
        ll ans=0;
        ll nummax=0;
        for(int i=0;i<k;i++){
            hash[nums[i]]++;
            nummax+=nums[i];
        }
        if(hash.size()>=m){
            ans=max(ans,nummax);
        }
       
        for(int i=0;i+k<nums.size();i++){
                if(hash[nums[i]]==1){
                    hash.erase(nums[i]);
                }
                else{
                    hash[nums[i]]--;
                }
                hash[nums[i+k]]++;
                nummax-=nums[i];
                nummax+=nums[i+k];
                if(hash.size()>=m){
                    ans=max(ans,nummax);
                }
            
        }
         return ans; 
    }
};
int main(){
    vector<int>v={5,9,9,2,4,5,4};
    Solution s;
    s.maxSum(v,1,3);
return 0;
}