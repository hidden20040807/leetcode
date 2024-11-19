#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>getZ(string s){
        int n=s.size();
        vector<int>z(n,0);
        z[0]=n;
        for(int i=1,l=-1,r=-1;i<n;i++){
            if(i<=r)z[i]=min(r-i+1,z[i-l]);
            while(s[z[i]]==s[i+z[i]])z[i]++;
            if(i+z[i]-1>r)r=i+z[i]-1,l=i;
        }
        return z;
    }
    
    int minStartingIndex(string s, string pattern) {
        vector<int>z1=getZ(pattern+s);
        reverse(s.begin(),s.end());
        reverse(pattern.begin(),pattern.end());
        vector<int>z2=getZ(pattern+s);
        int n=pattern.size();
        int sl=s.size();
        for(int i=n;i<=sl;i++){
            if(z1[i]+z2[sl-i+n]>=n-1)
            return i-n;
        }
        return -1;
    }

};
int main(){
    string s1="abcd";
    string s2="dba";
    Solution s;
    cout<<s.minStartingIndex(s1,s2);
    return 0;
}
