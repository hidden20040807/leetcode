#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    void han(vector<int>& A, vector<int>& B, vector<int>& C,int n){
        if(n==1){
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        han(A,C,B,n-1);
        C.push_back(A.back());
        A.pop_back();
        han(B,A,C,n-1);
    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
       han(A,B,C,A.size());
    }
};
int main(){
    return 0;
}