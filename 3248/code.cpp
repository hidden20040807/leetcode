#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans=0;
        for(string s:commands){
            if(s=="RIGHT"){
                ans++;
            }
            else if(s=="LEFT"){
                ans--;
            }
            else if(s=="DOWN"){
                ans+=n;
            }
            else{
                ans-=n;
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}