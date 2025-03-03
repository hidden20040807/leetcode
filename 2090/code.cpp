#include<bits\stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        ll val=0;
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n&&i<=k;i++){
            val+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(i-k>=0&&i+k<n){
                ans[i]=val/(2*k+1);
            }
            else{
                ans[i]=-1;
            }
            if(i-k>=0){
                val-=nums[i-k];
            }
            if(i+k+1<n){
                val+=nums[i+k+1];
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}