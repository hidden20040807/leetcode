#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
    int avg(vector<vector<int>>& img,int i,int j){
            int n=0;
            int sum=0;
            for(vector<int>d:dir){
                int x=i+d[0];
                int y=j+d[1];
                int row=img.size();
                int col=img[0].size();
                if(x>=0&&x<row&&y>=0&&y<col){
                    sum+=img[x][y];
                    n++;
                }
            }
            return sum/n;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>>ans(img.size(),vector<int>(img[0].size()));
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){
                ans[i][j]=avg(img,i,j);
            }
        }
        return ans;
    }
};
int mai(){
    return 0;
}