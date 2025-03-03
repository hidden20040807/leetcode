#include<bits\stdc++.h>
using namespace std;
using tiii=tuple<int,int,int>;
class Solution {
public:
    
    int dfs(vector<int>& nums,int i,int op1,int op2,int k,vector<vector<vector<int>>>&hash){
        if(i<0)
        return 0;
        if(hash[i][op1][op2]!=-1){
            return hash[i][op1][op2];
        }
        if(op1==0&&op2==0){
            int ans=dfs(nums,i-1,0,0,k,hash)+nums[i];
            hash[i][op1][op2]=ans;
            return ans;
        }
        int n1=dfs(nums,i-1,op1,op2,k,hash)+nums[i];
        int n2=dfs(nums,i-1,op1,op2,k,hash)+nums[i];
        int n3=dfs(nums,i-1,op1,op2,k,hash)+nums[i];
        if(op1>0){
            n1=dfs(nums,i-1,op1-1,op2,k,hash)+(nums[i]+1)/2;
        }
        if(op2>0&&nums[i]>=k){
            n2=dfs(nums,i-1,op1,op2-1,k,hash)+(nums[i]-k);
        }
        if(op2>0&&op1>0&&nums[i]>=k){
            n3=dfs(nums,i-1,op1-1,op2-1,k,hash)+(nums[i]-k+1)/2;
            if((nums[i]+1)/2>=k){
                n3=min(n3,dfs(nums,i-1,op1-1,op2-1,k,hash)+(nums[i]+1)/2-k);
            }
        }
        int ans=min(n1,n2);
        ans=min(ans,n3);
        hash[i][op1][op2]=ans;
        
        return hash[i][op1][op2];

    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n=nums.size();
        vector<vector<vector<int>>>hash(n,vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return dfs(nums,n-1,op1,op2,k,hash);
    }
};
int main(){
    Solution s;
    vector<int>v{2,4,3};
    s.minArraySum(v,3,2,1);
    
    return 0;
}