#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
            int negnum=0;
            long long  ans=1;
            int maxneg=-9;
            int pos=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]){
                    ans*=nums[i];
                    if(nums[i]<0){
                        maxneg=max(maxneg,nums[i]);
                        negnum++;
                    }
                    else{
                        pos++;
                    }
                }
            }
           if(negnum%2){
                if(nums.size()>1){
                    ans/=maxneg;
                    negnum--;
                }
           }
           if(negnum==0&&pos==0)
           ans=0;

           
            return ans;
    }
};
int main(){
   
    return 0;
}