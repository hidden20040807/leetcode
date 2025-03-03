#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                res[i]=nums[i];
            }
            else if(nums[i]>0){
                int k=nums[i];
                res[i]=nums[(i+k)%n];
                
            }
            else{
                 int k=nums[i];
                res[i]=nums[(i+k+100*n)%n];
            }
        }
        return res;
    }
};
int main(){
    return 0;
}