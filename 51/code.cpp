#include<bits\stdc++.h>
using namespace std;
using  pii= pair<int,int>;
class Solution {
public:
    vector<vector<string>>ans;
    void dfs(int&n,vector<int>&path,vector<bool>&col,vector<pii>&diag,int&row){
        if(n==path.size()){
            vector<string>v;
            for(int i=0;i<n;i++){
                string s;
                for(int j=0;j<n;j++){
                    if(j==path[i]){
                        s.push_back('Q');
                    }
                    else{
                        s.push_back('.');
                    }
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            float i=row;
            bool flag=true;
            for(int n=0;n<diag.size();n++){
                if(j==diag[n].second)
                continue;
                float k=abs((i-diag[n].first)/(j-diag[n].second));
                if(k==1)
                flag=false;
            }
            if(flag&&!col[j]){
                col[j]=true;
                path.push_back(j);
                diag.push_back({row,j});
                row++;
                dfs(n,path,col,diag,row);
                col[j]=false;
                path.pop_back();
                diag.pop_back();
                row--;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>col(n,false);
        int row=0;
        vector<pii>diag;
        vector<int>path;
        dfs(n,path,col,diag,row);
        return ans;
    }
};
int main(){
    Solution s;
   vector<vector<string>>ans= s.solveNQueens(2);
    return 0;
}