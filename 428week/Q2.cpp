#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        map<string ,double>num1;
        map<string ,double>num2;
        
        function<void(string,double)> dfs1=[&](string name, double num)->void{
            num1[name]=num;
            for(int i=0;i<pairs1.size();i++){
                if(pairs1[i][0]==name){
                    dfs1(pairs1[i][1],num*rates1[i]);
                }
            }
        };
         function<void(string,double)> dfs2=[&](string name, double num)->void{
            num2[name]=num;
            for(int i=0;i<pairs2.size();i++){
                if(pairs2[i][1]==name){
                    dfs2(pairs2[i][0],num*rates2[i]);
                }
            }
        };
        dfs1(initialCurrency,1);
        dfs2(initialCurrency,1);
        double ans=1;
        for(auto [s,num]:num1){
                if(num2.count(s)){
                    ans=max(ans,num/num2[s]);
                }
        }
        return ans;
    }
};
int main(){
    vector<vector<string>>s1={{"EUR","USD"},{"USD","JPY"}};
    vector<double>r1={2,3};
    vector<vector<string>>s2={{"JPY","USD"},{"USD","CHF"},{"CHF","EUR"}};
    vector<double>r2={4,5,6};
    Solution s;
    cout<<s.maxAmount("EUR",s1,r1,s2,r2);
    return 0;
}