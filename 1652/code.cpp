#include<bits\stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0){
            return ans;
        }
        int num=0;
        
        for(int i=0;i<abs(k);i++){
            num+=code[i];
        }
        
        for(int i=0;i<n;i++){
            num-=code[i];
            num+=code[(i+abs(k))%n];
            if(k<0)
            ans[(i+abs(k)+1)%n]=num;
            else
            ans[i]=num;
        }
        return ans;
    }
};
int main(){
    vector<int>v={2,4,9,3};
    Solution s;
    s.decrypt(v,-2);
    return 0;
}