#include<bits\stdc++.h>
using namespace std;
//回溯算法，注意一下不必要的路径
class Solution {
public:
    vector<string>ans;
    void dfs(int &n,stack<char>&stack,int &left,string &path){
        if(stack.empty()&&left==n){
            ans.push_back(path);
            return;
        }
            if(left<n){
            path.push_back('(');
            left++;
            stack.push('(');
            dfs(n,stack,left,path);
            path.erase(path.size()-1);
            left--;
            stack.pop();
            }
            if(!stack.empty()){
                stack.pop();
                path.push_back(')');
                dfs(n,stack,left,path);
                stack.push('(');
                path.erase(path.size()-1);
            }
       

    }
    vector<string> generateParenthesis(int n) {
        stack<char>stack;
        int left=0;
        string s;
        dfs(n,stack,left,s);
        return ans;
    }
};
int main(){
    return 0;
}