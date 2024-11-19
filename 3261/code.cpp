#include<bits\stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
class Solution {
public:
    
    vector<ll> pre1(string s,int k){
        vector<ll>pre(s.size(),0);
        int size=s.size();
        int left=0;
        int right=-1;
        int num_0=0;
        int num_1=0;
        while(right<size){
            while(right<size&&(num_0<=k||num_1<=k)){
                if(right>=0){
                    pre[right]=left;
                }
                right++;
                if(s[right]=='0'){
                    num_0++;
                }
                else{
                    num_1++;
                }
            }
            while(left<=right&&(num_0>k&&num_1>k)){
                if(s[left]=='0'){
                    num_0--;
                }
                else{
                    num_1--;
                }
                left++;
            }
        }
        return pre;
    }
    vector<ll> pre2(vector<ll>pre){
        ll n=0;
        vector<ll>ans(pre.size());
        for(int i=0;i<pre.size();i++){
            n+=i-pre[i]+1;
            ans[i]=n;
        }
        return ans;
    }
    ll check(string &s,int k ,int l,int r,vector<ll>&pre,vector<ll>&p){
        int left=l;
        int right=r+1;
        ll ans=0;
        while(left<right){
            int mid=(left+right)>>1;
            if(pre[mid]<=l){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        ll n=(left-l);
        ans+=n*(n+1)/2;
        ans+=p[r]-(left-1>=0?p[left-1]:0);
        return ans;
    }
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        vector<ll>ans;
        vector<ll>pre=pre1(s,k);
        vector<ll>p=pre2(pre);
        for(vector<int>n:queries){
            ll num=check(s,k,n[0],n[1],pre,p);
                ans.emplace_back(num);
            
        }
        return ans; 
    
    }
};
int main(){
    vector<vector<int>>q{{0,5}};
    string s="010101";
    Solution ss;
    ss.countKConstraintSubstrings(s,1,q);
    return 0;
}