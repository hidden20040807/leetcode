#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool row[9][10];
    bool col[9][10];
    bool block[9][10];
    bool dfs(vector<vector<char>>& board,int& i,int& j){
            if(i==9){
                return true;
            }
            if(board[i][j]=='.'){
                for(int k=1;k<=9;k++){
                    if(!row[i][k]&&!col[j][k]&&!block[(i/3)*3+j/3][k]){
                            board[i][j]=k+'0';
                            row[i][k]=true;
                            col[j][k]=true;
                            block[(i/3)*3+j/3][k]=true;
                            if(j==8){
                                j=0;
                                i++;
                                if(dfs(board,i,j)){
                                    return true;
                                }
                                j=8;
                                i--;
                            } 
                            else{
                                j++;
                                 if(dfs(board,i,j)){
                                    return true;
                                }
                                j--;
                            }
                            row[i][k]=false;
                            col[j][k]=false;
                            block[(i/3)*3+j/3][k]=false;
                            board[i][j]='.';

                    }
                }
                return false;
            }
            else{
                 if(j==8){
                    j=0;
                    i++;
                    if(dfs(board,i,j)){
                        return true;
                    }
                    j=8;
                    i--;
                } 
                else{
                    j++;
                    if(dfs(board,i,j)){
                        return true;
                    }
                    j--;
                }
                return false;
            }
           
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    row[i][num]=true;
                    col[j][num]=true;
                    block[(i/3)*3+j/3][num]=true;
                }
            }
        }
        int i=0;
        int j=0;
        dfs(board,i,j);
    }
};
int main(){
    
    return 0;
}