#include<bits\stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    ll f[400001];
    ll lazy[400001];
    void add(int l,int r,int x,int y,int k){
            if(x==l&&y==r){
                lazy[k]+=1;
                return;
            }
            f[k]+=(y-x+1);
            int mid=(l+r)>>1;
            if(y<=mid){
                add(l,mid,x,y,2*k+1);
            }
            else if(x>mid){
                add(mid+1,r,x,y,2*k+2);
            }
            else{
                add(l,mid,x,mid,2*k+1);
                add(mid+1,r,mid+1,y,2*k+2);
            }
    }
    ll cal(int k,int l,int r,int x,int y){
        if(l==x&&r==y){
            return f[k]+lazy[k];
        }
        if(lazy[k]){
            lazy[2*k+1]+=lazy[k];
            lazy[2*k+2]+=lazy[k];
            lazy[k]=0;
        }
        int mid=(l+r)>>1;
        int ans=0;
            if(y<=mid){
               ans=cal(2*k+1,l,mid,x,y);
            }
            else if(x>mid){
                ans=cal(2*k+2,mid+1,r,x,y);
            }
            else{
                ans=cal(k+k+1,l,mid,x,mid)+cal(k+k+1,mid+2,r,mid+1,y);
            }
            f[k]=f[2*k+1]+f[2*k+2]+lazy[2*k+1]*(mid-l+1)+lazy[2*k+2]*(r-mid);
            return ans;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        for(vector<int>q:queries){
            add(0,nums.size()-1,q[0],q[1],0);
        }
        for(int i=0;i<nums.size();i++){
            if(cal(0,0,nums.size()-1,i,i)<nums[i]){
                return false;
            }
        }
        return true;
        
    }
};
int  main(){
    return 0;
}