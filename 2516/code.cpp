#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>num(3,0);
        for(char ch:s){
            num[ch-'a']++;
        }
        for(int n:num){
            if(n-k<0)
            return -1;
        }
        int right=-1;
        int left=0;
        int ans=0;
        while(right<(int)s.size()){
            while(right<(int)s.size()&&(num[0]-k>=0&&num[1]-k>=0&&num[2]-k>=0)){
                right++;
                if(right<s.size())
                num[s[right]-'a']--;
            }
            ans=max(ans,right-left);
            while(left<=right&&!(num[0]-k>=0&&num[1]-k>=0&&num[2]-k>=0)){
                num[s[left]-'a']++;
                left++;
            }
        }
        return  s.size()-ans;

    }
};
int main(){
    Solution s;
    string s1="aabaaaacaabc";
    cout<<s.takeCharacters(s1,2);
    return 0;
}