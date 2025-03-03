#include<bits\stdc++.h>
using namespace std;
class Solution {
    public:
        int minSwaps(vector<int>& nums) {
            vector<int>roll;
            roll.insert(roll.end(),nums.begin(),nums.end());
            roll.insert(roll.end(),nums.begin(),nums.end());
            int cnt=0;
            for(int n:nums){
                if(n==1)
                cnt++;
            }
            int num=0;
            int ans=cnt;
            for(int i=0;i<cnt;i++){
                if(nums[i]==0)
                num++;
            }
            for(int i=0;i<nums.size();i++){
                if(roll[i]==0){
                    num--;
                }
                if(roll[i+cnt]==0){
                    num++;
                }
                ans=min(ans,num);
            }
            return ans;
        }
    };
int main(){
    return 0;
}