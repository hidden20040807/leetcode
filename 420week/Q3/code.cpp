#include<bits\stdc++.h>
using namespace std;
const int MA=1e6+1;
int lcp[MA];
class Solution {
public:
    
    void init(){
        lcp[1]=1;
        for(int i=2;i<MA;i++){
            if(!lcp[i]){
                for(int j=i;j<MA;j=j+i){
                    if(!lcp[j]){
                        lcp[j]=i;
                    }
                }
            }
        }
    }
    int minOperations(vector<int>& nums) {
        init();
        int ans=0;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                nums[i]=lcp[nums[i]];
                if(nums[i]>nums[i+1]){
                    return -1;
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}