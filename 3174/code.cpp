#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        vector<bool>flag(n,true);
        for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9'){
                flag[i]=false;
                int j=i;
                while(j>=0){
                    if(flag[j]&&!(s[j]>='0'&&s[j]<='9')){
                        flag[j]=false;
                        break;
                    }
                    j--;
                }
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(flag[i]){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    string ss="abc";
    cout<<s.clearDigits(ss);
    return 0;
}