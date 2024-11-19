#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int checkrow(vector<vector<int>>& grid){
            int ans=0;
            for(vector<int>v:grid){
                int left=0;
                int right=v.size()-1;
                while(left<right){
                    if(v[left]!=v[right]){
                        ans++;
                    }
                    left++;
                    right--;
                }
            }
            return ans;
    }
    int checkcol(vector<vector<int>>& grid){
        int ans=0;
        for(int j=0;j<grid[0].size();j++){
            int up=0;
            int down=grid.size()-1;
            while(up<down){
                if(grid[up][j]!=grid[down][j]){
                    ans++;
                }
                up++;
                down--;
            }
        }
        return ans;
    }
    int minFlips(vector<vector<int>>& grid) {
        return min(checkrow(grid),checkcol(grid));
    }
};
int main(){
    vector<vector<int>>v{{1,0},{0,1}};
    Solution s;
    cout<<s.minFlips(v);
    return 0;
}