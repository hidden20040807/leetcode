#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
     bool dfs(vector<vector<char>>& board,int i,int j,string &word,int k,vector<vector<bool>>&flag){
        if(word[k]==board[i][j]){
            if(k==word.size()-1)
            return true;
        }
        else{
            return false;
        }
        bool down=false;
        bool up=false;
        bool left=false;
        bool right=false;
        flag[i][j]=true;
        if(i+1<board.size()&&!flag[i+1][j]){
            down=dfs(board,i+1,j,word,k+1,flag);
        }
        if(i-1>=0&&!flag[i-1][j]){
             up=dfs(board,i-1,j,word,k+1,flag);
        }
        if(j+1<board[0].size()&&!flag[i][j+1]){
            right=dfs(board,i,j+1,word,k+1,flag);
        }
        if(j-1>=0&&!flag[i][j-1]){
            left=dfs(board,i,j-1,word,k+1,flag); 
        }
        flag[i][j]=false;
        if(up||down||right||left){
            return true;
        }
        else{
            return false;
        }
     } 
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>>flag(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,i,j,word,0,flag))
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<vector<char>> board{{'a','a'}};
    string word="aaa";
    cout<<s.exist(board,word);
    return 0;
}