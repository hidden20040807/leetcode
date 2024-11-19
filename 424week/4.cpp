#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int minDifference(vector<int>& nums) {
        nums.insert(nums.begin(),0);
        nums.insert(nums.end(),0);
        vector<vector<int>>pre;
        int ans=0;
        int left,right,n;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=-1&&nums[i+1]!=-1){
                ans=max(ans,abs(nums[i]-nums[i-1]));
            }
            else if(nums[i]!=-1&&nums[i+1]==-1){
                n=1;
                left=nums[i];
            }
            else if(nums[i]==-1&&nums[i+1]!=-1){
                right=nums[i+1];
                pre.push_back({left,right,n});
            }
            else{
                n++;
            }
        }
        for(vector<int>v:pre){
            double l=v[0];
            double r=v[1];
            int num=v[2];
            ans=max(ans,(int)ceil(abs(l-r)/num));
        }
        return ans;
    }
};
int  main(){
    Solution s;
    vector<int>v{1,2,-1,10,8};
    s.minDifference(v);
    return 0;
}