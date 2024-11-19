#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size();
        for(int i=0;i<n-1;i++){
            char ch1=s[i];
            char ch2=s[i+1];
            int n1=ch1-'0';
            int n2=ch2-'0';
            if(n1%2==n2%2&&n1>n2){
                char ch=ch1;
                s[i]=s[i+1];
                s[i+1]=ch;
                return s;
            }
        }
        return s;

    }
};
int main(){
    return 0;
}