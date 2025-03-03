#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min=0;
        int n=blocks.size();
        int ans=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                min++;
                ans++;
            }
        }
        for(int i=0;i+k<n;i++){
            if(blocks[i+k]=='W')
            min++;
            if(blocks[i]=='W')
            min--;
            ans=std::min(ans,min);
        }
           
        return ans;
    }
};
int main(){
    return 0;
}