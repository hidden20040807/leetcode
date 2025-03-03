#include<bits\stdc++.h>
class Solution {
public:
    unordered_set<int>hash;
    bool hasAllCodes(string s, int k) {
        int num=0;
        for(int i=0;i<k&&i<s.size();i++){
            num+=s[i]-'0';
            num<<1;
        }
        num>>1;
        hash.insert(num);
        for(int i=0;i+k<s.size();i++){
            num-=(s[i]-'0')<<k-1;
            num<<1;
            num+=s[i+k]-'0';
            if(!hash.count(num))
            hash.insert(num);
        }
        return hash.size()==(int)pow(2,k);
    }
};
using namespace std;
int main(){
    Solution s;
    cout<<s.hasAllCodes("00110110",2);
    return 0;
}