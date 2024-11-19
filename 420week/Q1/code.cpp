#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> stringSequence(string target) {
            string s="";
            vector<string>ans;
            int i=0;
            int n=target.size();
            while(i<n){
                char ch='a';
                while(ch<=target[i]){
                    ans.push_back(s+ch);
                    ch++;
                }
                s=s+ch;
                i++;
            }
            return ans;

    }
};
int main(){
    return 0;
}