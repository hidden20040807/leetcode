#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    void update(int left,int right,vector<int>&v,vector<vector<int>>&con){
        if(v[left]+1<v[right]){
            con[right].push_back(left);
            v[right]=v[left]+1;
            for(int i=right+1;i<v.size();i++){
                for(int n:con[i]){
                    if(v[i]>v[n]+1){
                        v[i]=v[n]+1;
                    }
                }
            }
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
            vector<int>v(n);
            vector<vector<int>>con(n);
            for(int i=0;i<n;i++){
                if(i!=0)
                con[i]={i-1};
                v[i]=i;
            }
            vector<int>ans;
            for(vector<int>q:queries){
                update(q[0],q[1],v,con);
                ans.push_back(v[n-1]);
            }
            return ans;

    }
};
int main(){
    Solution s;
    vector<vector<int>>v{{1,5},{3,6},{0,3}};
    s.shortestDistanceAfterQueries(7,v);
    return 0;
}