#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>hash1;
        unordered_set<string>hash2;
        for(vector<string>v:paths){
            if(hash2.count(v[0])){
                hash2.erase(v[0]);
            }
            else{
                hash1.insert(v[0]);
            }
            if(hash1.count(v[1])){
                hash2.erase(v[1]);
            }
            else{
                hash2.insert(v[1]);
            }

        }
        return *hash2.begin();
    }
};
int main(){
    return 0;
}