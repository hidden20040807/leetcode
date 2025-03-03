#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    map<string,int>map1;
    map<string ,int>map2;
    bool isPossibleToRearrange(string s, string t, int k) {
        for(int i=0;i<s.size();i=i+k){
            string s1=s.substr(i,i+k-1);
            string s2=t.substr(i,i+k-1);
            if(!map1.count(s1))
            map1[s1]=1;
            else
            map1[s1]++;
             if(!map2.count(s2))
            map1[s2]=1;
            else
            map1[s2]++;
        }
        for(auto p:map1){
            if(p.second!=map2[p.first])
            return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    s.isPossibleToRearrange("aabbcc","bbaacc",2);
    return 0;
}