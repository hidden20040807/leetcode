#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>hash;
        vector<int>ans;
        for(int num:nums){
            if(hash.count(num)==0){
                hash.emplace(num);
            }
            else{
                ans.push_back(num);
            }
        }
        return ans;

    }
};
int main(){
    return 0;
}