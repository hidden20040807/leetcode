#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int max=0;
        int n=grumpy.size();
        for(int i=0;i<minutes;i++){
            if(grumpy[i]){
                ans+=customers[i];
                max+=customers[i];
            }
        }
        for(int i=0;i<n-minutes;i++){
            if(grumpy[i+minutes]){
                max+=customers[i+minutes];
            }
            if(grumpy[i]){
                 max-=customers[i];
            }
            ans=std::max(ans,max);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(!grumpy[i])
            sum+=customers[i];
        }
        return sum+ans;
    }
};
int main(){
    return 0;
}