#include<bits\stdc++.h>
using namespace std;
struct moves{
    int i;
    int j;
    int dx;
    int dy;
    int step;
};
class Solution {
public:
    int rook_dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    int queen_dir[8][2]={{-1,0},{1,0},{0,1},{0,-1},{-1,1},{1,-1},{1,1},{-1,-1}};
    int bishop_dir[4][2]={{-1,1},{1,-1},{1,1},{-1,-1}};
    vector<moves>path;
    int dfs(vector<string>& pieces,vector<vector<int>>& positions,int k){
        int n=pieces.size();
        if(k==n)
        return 1;
        int ans=0;
        if(pieces[k]=="rook"){
            bool f=true;
            for(moves m:path){
                moves m0={positions[k][0]-1,positions[k][1]-1,0,0,0};
                if(!check(m,m0)){
                    f=false;
                }
            }
            if(f){
                moves m0={positions[k][0]-1,positions[k][1]-1,0,0,0};
                path.push_back(m0);
                ans+=dfs(pieces,positions,k+1);
                path.pop_back();
            }
            for(int i=0;i<4;i++){
                int step=1;
                 int x=positions[k][0]+rook_dir[i][0]-1;
                 int y=positions[k][1]+rook_dir[i][1]-1;
                 while(x>=0&&x<8&&y>=0&&y<8){
                    moves m0={positions[k][0]-1,positions[k][1]-1,rook_dir[i][0],rook_dir[i][1],step};
                    bool flag=true;
                    for(moves m:path){
                        if(!check(m,m0)){
                            flag=false;
                        }
                    }
                    if(flag){
                         path.push_back(m0);
                    ans+=dfs(pieces,positions,k+1);
                    path.pop_back();
                    }
                    step++;
                   x+=rook_dir[i][0];
                   y+=rook_dir[i][1];
                }
            }
        }
        if(pieces[k]=="queen"){
            bool f=true;
            for(moves m:path){
                moves m0={positions[k][0]-1,positions[k][1]-1,0,0,0};
                if(!check(m,m0)){
                    f=false;
                }
            }
            if(f){
                moves m0={positions[k][0]-1,positions[k][1]-1,0,0,0};
                path.push_back(m0);
                ans+=dfs(pieces,positions,k+1);
                path.pop_back();
            }
            for(int i=0;i<8;i++){
                int step=1;
                 int x=positions[k][0]+queen_dir[i][0]-1;
                 int y=positions[k][1]+queen_dir[i][1]-1;
                 while(x>=0&&x<8&&y>=0&&y<8){
                    moves m0={positions[k][0]-1,positions[k][1]-1,queen_dir[i][0],queen_dir[i][1],step};
                    bool flag=true;
                    for(moves m:path){
                        if(!check(m,m0)){
                            flag=false;
                        }
                    }
                    if(flag){
                    path.push_back(m0);
                    ans+=dfs(pieces,positions,k+1);
                    path.pop_back();
                    }
                    step++;
                   x+=queen_dir[i][0];
                   y+=queen_dir[i][1];
                }
            }
        }
        if(pieces[k]=="bishop"){
            bool f=true;
            for(moves m:path){
                moves m0={positions[k][0]-1,positions[k][1]-1,0,0,0};
                if(!check(m,m0)){
                    f=false;
                }
            }
            if(f){
                moves m0={positions[k][0]-1,positions[k][1]-1,0,0,0};
                path.push_back(m0);
                ans+=dfs(pieces,positions,k+1);
                path.pop_back();
            }
            for(int i=0;i<4;i++){
                int step=1;
                 int x=positions[k][0]+bishop_dir[i][0]-1;
                 int y=positions[k][1]+bishop_dir[i][1]-1;
                 while(x>=0&&x<8&&y>=0&&y<8){
                    moves m0={positions[k][0]-1,positions[k][1]-1,bishop_dir[i][0],bishop_dir[i][1],step};
                    bool flag=true;
                    for(moves m:path){
                        if(!check(m,m0)){
                            flag=false;
                        }
                    }
                    if(flag){
                    path.push_back(m0);
                    ans+=dfs(pieces,positions,k+1);
                    path.pop_back();
                    }
                    step++;
                   x+=bishop_dir[i][0];
                   y+=bishop_dir[i][1];
                }
            }
        }
        return ans;

    }
    bool check(moves m1,moves m2){
        int x1=m1.i;
        int y1=m1.j;
        int x2=m2.i;
        int y2=m2.j;
        int step1=m1.step;
        int step2=m2.step;
        while(x1>=0&&x1<8&&y1>=0&&y1<8&&x2>=0&&x2<8&&y2>=0&&y2<8&&(step1!=0||step2!=0)){
            if(x1==x2&&y1==y2)
            return false;
            if(step1>0){
                x1+=m1.dx;
                y1+=m1.dy;
                step1--;
            }
            if(step2>0){
                x2+=m2.dx;
                y2+=m2.dy;
                step2--;
            }
        }
        return !(x1==x2&&y1==y2);
    }
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
          return dfs(pieces,positions,0);

    }
};
int main(){
    vector<string>p{"rook","rook"};
    vector<vector<int>> positions{{1,1},{8,8}};
    Solution s;
    cout<<s.countCombinations(p,positions);
    return 0;
}