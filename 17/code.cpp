#include<bits\stdc++.h>
using namespace std;
//很简单的回溯穷举
class Solution {
public:
    vector<vector<char>>number={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    vector<string>ans;
    void dfs(string &digits,int &depth,string &path){
        if(depth==digits.size()){
             if(digits!="")
            ans.push_back(path);
            return;
        }
        int n=(int)(digits[depth]-'0');
        for(char ch:number[n]){
            path.push_back(ch);
            depth++;
            dfs(digits,depth,path);
             path.erase(path.size()-1);
             depth--;
        }
       
    }
    
    vector<string> letterCombinations(string digits) {
        string path;
        int depth=0;
        dfs(digits,depth,path);
        return ans;
    }
};
int main(){
    
    return 0;
}