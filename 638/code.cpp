#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    map<vector<int>,int>memo;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return serch(price,special,needs);
    }
    int serch(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        if(!(memo.count(needs))){
            int ans=0;
            int n=price.size();
            for(int i=0;i<n;i++){
                ans+=price[i]*needs[i];
            }
            for(auto v:special){
                 bool f=true;
                 int n=v.size();
                 vector<int>need;
                 for(int i=0;i<n-1;i++){
                    if(needs[i]<v[i]){
                        f=false;
                        break;
                    }
                    need.emplace_back(needs[i]-v[i]);
                 }
                 if(f){
                    ans=min(ans,v[n-1]+serch(price,special,need));
                 }
            }
            memo[needs]=ans;
        }
        return memo[needs];
    }    
};
int main(){
    Solution s;
    vector<int>price{2,3,4};
    vector<vector<int>>special{{1,1,0,4},{2,2,1,9}};
    vector<int>needs{1,2,1};
    cout<<s.shoppingOffers(price,special,needs);
    return 0;
}