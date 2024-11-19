#include<bits\stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    ll f[400001];
    ll lazy[400001];
    void add(int l,int r,int x,int y,int k,int z){
            if(x==l&&y==r){
                lazy[k]+=z;
                return;
            }
            f[k]+=(y-x+1);
            int mid=(l+r)>>1;
            if(y<=mid){
                add(l,mid,x,y,2*k+1,z);
            }
            else if(x>mid){
                add(mid+1,r,x,y,2*k+2,z);
            }
            else{
                add(l,mid,x,mid,2*k+1,z);
                add(mid+1,r,mid+1,y,2*k+2,z);
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int num=0;
        for(int n:nums){
            num+=n;
        }
        if(num==0){
            return 0;
        }
        int k=1;
        for(vector<int>q:queries){
            add(0,nums.size()-1,q[0],q[1],0,q[2]);
            bool flag=true;
            for(int i=0;i<nums.size();i++){
            if(cal(0,0,nums.size()-1,i,i)<nums[i]){
                flag=false;
                break;
            }
         }
        if(!flag)
            k++;
        else{
            return k;
        }
        }
        return -1;
        
    }
};
int  main(){
    return 0;
}