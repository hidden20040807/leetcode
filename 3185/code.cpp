#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans=0;
        int n=hours.size();
        vector<int>hash(24,0);
        for(int i=0;i<n;i++){
            ans+=hash[(24-hours[i]%24)%24];
            hash[hours[i]%24]++;
        }
        return ans;
    }
};
int main(){
    return 0;
}