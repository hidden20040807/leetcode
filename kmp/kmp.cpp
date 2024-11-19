#include<bits\stdc++.h>
using namespace std;

vector<int> getNext(string s){
        vector<int>next(s.size());
        next[0]=-1;
        int j=0,k=-1;
        while(j<s.size()-1){
           if(k==-1||s[j]==s[k]){
            j++,k++;
            if(s[j]==s[k]){
                next[j]=next[k];
            }
            else{
                next[j]=k;
            }
           }
           else
           k=next[k];
        }
        return next;
}
int main(){
    vector<int>v=getNext("abacabab");
    for(int n:v){
        cout<<n<<" ";
    }
    return 0;
}