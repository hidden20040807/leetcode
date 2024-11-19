#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        vector<unordered_set<string>>hash(26,unordered_set<string>());
        for(string s:ideas){
            string sub=s.substr(1,s.size()-1);
            hash[s[0]-'a'].insert(sub);
        }
        for(int i=0;i<25;i++){
            if(hash[i].size()==0)
            continue;
            for(int j=i+1;j<26;j++){
                if(hash[j].size()==0)
                continue;
                int sum=0;
                for(string s:hash[i]){
                    if(hash[j].count(s))
                    sum++;
                }
                 ans+=(hash[i].size()-sum)*(hash[j].size()-sum);
            }
           
        }
       return ans*2;
       
         
    }
};
int main(){
    return 0;
}