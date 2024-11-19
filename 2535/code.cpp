#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int x=0;
        int y=0;
        for(int n:nums){
            x+=n;
            while(n){
                y+=n%10;
                n/=10;
            }
        }    
        return abs(x-y);  
    }
};
int main(){
    return 0;
}