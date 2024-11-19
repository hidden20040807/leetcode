#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                   for(int k=0;k<n;k++){
                        if(k!=j&&k!=i){
                           int n1= (int)(log2(nums[k]))+1;
                           int n2= (int)(log2(nums[j]))+1;
                           int num=(nums[i]<<((n1+n2)))+(nums[j]<<(n1))+nums[k];
                            ans=max(ans,num);
                        }
                    }  
                }
               
            }
        }   
        return ans;   
    }
};
int main(){
    Solution s;
    vector<int>n{1,2,3};
    cout<<s.maxGoodNumber(n);
    return 0;
}