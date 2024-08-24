#include<bits\stdc++.h>
using namespace std;

vector<int> getNext(string s){
        vector<int>next(s.size());
        next[0]=0;
        int len=0;
        int right=1;
        while(right<next.size()){
            if(s[len]==s[right]){
                len++;
                next[right]=len;
                right++;
            }
            else{
                if(len==0){
                    next[right]=0;
                    right++;
                }
                else{
                    len=next[len-1];
                }
            }
            
        }
        return next;
}
int main(){
    vector<int>v=getNext("abacabab");
    for(int n:v){
        cout<<n;
    }
    return 0;
}