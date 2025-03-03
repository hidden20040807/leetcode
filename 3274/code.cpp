#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    bool check(string s){
            if((s[0]-'0')%2==(s[1]-'a')%2)
            return true;
            return false;
    }
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return check(coordinate1)==check(coordinate2);
    }
};
int main(){
    return 0;
}