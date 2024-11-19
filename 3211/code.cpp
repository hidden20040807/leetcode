#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string>ans;
            for(int i=0;i<n;i++){
                vector<string>v;
                if(i==0){
                    ans.push_back("0");
                    ans.push_back("1");
                    continue;
                }
                else{
                   v=ans;
                   ans.clear(); 
                }
                for(string s:v){
                    int end=s.size();
                    if(s[end-1]=='0'){
                        ans.push_back(s+"1");
                    }
                    else{
                        ans.push_back(s+"1");
                        ans.push_back(s+"0");
                    }
                }
            }
            return ans;      
    }
};
int main(){

    return 0;
}