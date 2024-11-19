#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    int maxnum=1e5;
    ll ans=0;
    for(int j=0;j<n;j++){
        int x=0;
        int y=j;
        while(x<n&&y<n){
            maxnum=min(maxnum,v[x][y]);
            y++;
            x++;
        }
        if(maxnum<0)
        ans+=-1*maxnum;
        maxnum=1e5;
    }
    maxnum=1e5;
    for(int i=1;i<n;i++){
        int x=i;
        int y=0;
        while(x<n&&y<n){
            maxnum=min(maxnum,v[x][y]);
            y++;
            x++;
        }
       if(maxnum<0)
        ans+=-1*maxnum;
        maxnum=1e5;
    }
   cout<<ans<<endl;
   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}