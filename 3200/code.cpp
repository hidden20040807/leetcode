#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int ans=0;
        int i=red,j=blue;
        for(int k=1;;k++){
            if(k%2){
                if(i>=k){
                    ans=max(ans,k);
                    i-=k;
                }
                else{
                    break;
                }
            }
            else{
                if(j>=k){
                    ans=max(ans,k);
                    j-=k;
                }
                else{
                    break;
                }
            }
        } 
        i=blue,j=red;
        for(int k=1;;k++){
            if(k%2){
                if(i>=k){
                    ans=max(ans,k);
                    i-=k;
                }
                else{
                    break;
                }
            }
            else{
                if(j>=k){
                    ans=max(ans,k);
                    j-=k;
                }
                else{
                    break;
                }
            }
        }
        return ans;          
    }
    
};
int main(){
    return 0;
}