#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int dfs(int&n,string &path,int &num_A,int &num_L){
        if(n==path.size())
        return 1;
        int num=0;
       if(num_A<1&&num_L<2){
        
       }
    
        

    }
    int checkRecord(int n) {
        string path;
        int a=0;
        int l=0;
        return dfs(n,path,a,l);
    }
};
int main(){
    Solution s;
    cout<<s.checkRecord(10);
}