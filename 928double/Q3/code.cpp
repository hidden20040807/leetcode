#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
        vector<int>suf(n+1,m);
        for(int i=n-1, j=m-1;i>=0;i--){
            if(j>=0&&word1[i]==word2[j]){
                j--;
            }
            suf[i]=j+1;
        }
        vector<int>ans;
        bool flag=false;
        for(int i=0,j=0;i<n&&j<m;i++){
            if(!flag){
                if(word1[i]==word2[j]){
                    j++;
                    ans.push_back(i);
                }
                else if(suf[i+1]<=j+1){
                    j++;
                    flag=true;
                }
            }
            else{
                if(word1[i]==word2[j]){
                    ans.push_back(i);
                    j++;
                }
            }
        }
        if(ans.size()==m)
        return ans;
        return {};
    }
};
int main(){
    Solution s;
    s.validSequence("vbcca","abc");
    return 0;
}