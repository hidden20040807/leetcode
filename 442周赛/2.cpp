#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int find(int i,vector<int>&ans){
            if(ans[i]==i)
            return i;
                int j=find(ans[i],ans);
                ans[i]=j;
                return j;
        }
        void unions(int a,int b,vector<int>&ans){
            int i=find(a,ans);
            int j=find(b,ans);
            ans[j]=i;
        }
        void intersect(vector<int>a,vector<int>b,int k,vector<int>&ans,int i,int j,vector<bool>&flag ){
            vector<bool>arr1(100,false);
            vector<bool>arr2(100,false);
            for(int i=0;i<a.size();i++){
                arr1[i]=true;
            }
            for(int i=0;i<b.size();i++){
                arr2[i]=true;
            }
            int num=0;
           for(int i=0;i<100;i++){
            if(arr1[i]&&arr2[i]){
              num++;  
            }
           }
           if(num>=k){
                unions(i,j,ans);
                flag[i]=true;
                flag[j]=true;
           }
        }
        int numberOfComponents(vector<vector<int>>& properties, int k) {
            vector<int>ans(100);
            for(int i=0;i<100;i++){
                ans[i]=i;
            }
            vector<bool>flag(100,false);
            for(int i=0;i<properties.size()-1;i++){
                for(int j=i+1;j<properties.size();j++){
                    intersect(properties[i],properties[j],k,ans,i,j,flag);
                }
            }
            int num=0;
            set<int>hash;
            for(int i=0;i<100;i++){
                if(flag[i]&&!hash.count(i)){
                    hash.emplace(i);
                    num++;
                }
            }
            return num;

        }
    };
int main(){
    return 0;
}