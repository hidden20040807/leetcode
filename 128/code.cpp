#include<bits\stdc++.h>
using namespace std;
//这道题目要熟练运用哈希表，用unordered_set不排序，减少时间复杂度，寻找最长连续数字的过程就是在哈希表中找相应数字的过程，还有要去重，去掉重复的序列，如果该数字不是连续数字的开头，也就是n-1在哈希表里存在就不需要判断
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>set;
       for(int n:nums){
        set.emplace(n);
       } 
       int ans=0;
       for(unordered_set<int>::iterator it=set.begin();it!=set.end();it++){
            int n=*it;
            int len=0;
            if(set.find(n-1)==set.end()){
                while(set.count(n)){
                    len++;
                    n++;
                }
            }
            ans=max(len,ans);
       }
       return ans;
    }
};
int main(){
    return 0;
}