#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT32_MAX;
        for(int num:nums){
            int n=0;
            while(num){
                n+=num%10;
                num/=10;
            }
            ans=min(ans,n);
        }
        return ans;
    }
};
