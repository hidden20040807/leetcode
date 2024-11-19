#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans=0;
        int num1=0;
        int num2=0;
        
        for(char ch:text){
            if(ch==pattern[1]){
                num2++;
                ans+=num1;
            }
            if(ch==pattern[0]){
                num1++;
            }
            
        }
        return ans+max(num1,num2);
    }
};
int main(){
    Solution s;
    cout<<s.maximumSubsequenceCount("abdcdbc","ac");
    return 0;
}