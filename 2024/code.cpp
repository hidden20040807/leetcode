#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left=0;
        int right=0;
        int p=0;
        int ans=0;
        while(right<answerKey.size()){
             if(answerKey[right]=='T'){
                right++;
             }
             else if(p<k){
                p++;
                right++;
             }
             else{
                ans=max(ans,right-left);
                while(left<right){
                    if(answerKey[left]=='F')
                    p--;
                    left++;
                    if(p<k)
                    break;
                }
             }
        }
        ans=max(ans,right-left);
        left=0;
        right=0;
        p=0;
         while(right<answerKey.size()){
             if(answerKey[right]=='F'){
                right++;
             }
             else if(p<k){
                p++;
                right++;
             }
             else{
                ans=max(ans,right-left);
                while(left<right){
                    if(answerKey[left]=='T')
                    p--;
                    left++;
                    if(p<k)
                    break;
                }
             }
        }
         ans=max(ans,right-left);
        return ans;
        
    }
};
int main(){

    return 0;
}