#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int select=0;
        int ans=0;
        if(nums[0]>select){
            ans++;
        }
        select++;
        for(int i=0;i<n-1;i++){
            if(nums[i]<select&&nums[i+1]>select){
                ans++;
            }
            select++;
        }
        if(nums[n-1]<select){
            ans++;
        }
        return ans;
    }
};
int main(){
    vector<int>nums{1,1};
    Solution s;
    cout<<s.countWays(nums);
    return 0;
}