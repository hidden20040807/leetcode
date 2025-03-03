#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool judment(string s,int left,int right){
        while(left<right){
            if(s[right]==s[left]){
                right++;
                left--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        bool flag=true;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return judment(s,left+1,right)||judment(s,left,right-1);
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.validPalindrome("deeee");
    return 0;
}