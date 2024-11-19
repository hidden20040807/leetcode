#include<bits\stdc++.h>
using namespace std;
vector<int> getZ(string s){
    int n=s.size();
    vector<int>ans(n,0);
    ans[0]=n;
    for(int i=1,l=-1,r=-1;i<n;i++){
        if(i<=r)ans[i]=min(ans[i-l],r-i+1);
        while(s[ans[i]]==s[i+ans[i]])ans[i]++;
        if(i+ans[i]-1>r)l=i,r=ans[i]+i-1;
    }
    return ans;
}
int main(){
    string s="aaabaaaba";
    vector<int>v=getZ(s);
    for(int n:v){
        cout<<n<<" ";
    }
    return 0;
}