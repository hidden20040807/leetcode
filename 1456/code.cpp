#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int left=0;
        int right=left+k-1;
        int sum=0;
        for(int i=left;i<=right;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                sum++;
            }
        }
        ans=max(ans,sum);
        while(right<s.size()-1){
            right++;
             if(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u'){
                sum++;
               
            }
             if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u'){
                sum--;
             }                 
            ans=max(ans,sum);
            left++;
        }
        return ans;
    }
};
int main(){
    return 0;
}