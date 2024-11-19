#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int i=0;
        int j=0;
        vector<int>hash(26,0);
        int n=s.size();
        int max=0;
        int ans=0;
        while(j<n){
            while(j<n&&max<k){
                hash[s[j]-'a']++;
                max=std::max(hash[s[j]-'a'],max);
                j++;
            }
            if(max>=k)
            ans+=n-j+1;
            while(i<j){
                if(hash[s[i]-'a']==max){
                    hash[s[i]-'a']--;
                    max=0;
                    for(int i=0;i<26;i++){
                        max=std::max(max,hash[i]);
                    }

                }
                else{
                    hash[s[i]-'a']--;
                }
                i++;
                if(max>=k){
                    ans+=n-j+1;
                    
                }
                else{
                    break;
                }
            }

        } 
        return ans;
    }
};
int main(){
    Solution s;
    s.numberOfSubstrings("coganww",3);
    return 0;
}