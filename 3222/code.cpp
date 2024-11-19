#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    string losingPlayer(int x, int y) {
        while(true){
            if(x<1||y<4){
                return "Bob";
            }
            else{
                x--;
                y=y-4;
            }
            if(x<1||y<4){
                return "Alice";
            }
            else{
                x--;
                y=y-4;
            }
        }      
    }
};
int main(){
    return 0;
}