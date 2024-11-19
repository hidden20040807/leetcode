#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n=maximumHeight.size();
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        if(maximumHeight[0]<n)
        return -1;
        
        int max=maximumHeight[0]+1;
        long long ans=0;
        for(int num:maximumHeight){
            if(max==1)
            return -1;
            if(num<max){
                ans+=num;
                max=num;
            }
            else{
                ans+=max-1;
                max=max-1;
            }
           

        }
        return ans;

    }
};
