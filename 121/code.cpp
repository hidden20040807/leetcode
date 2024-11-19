#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxnum=0;
        int minnum=10000;
        for(int n:prices){
            minnum=min(minnum,n);
            maxnum=max(maxnum,n-minnum);
        }
        return maxnum;              
    }
};
int main(){
    return 0;
}