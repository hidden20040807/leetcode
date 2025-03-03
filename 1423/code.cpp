#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int n:cardPoints)
        sum+=n;
        int num=0;
         k=cardPoints.size()-k;
        for(int i=0;i<k;i++){
            num+=cardPoints[i];
        }
        int ans=sum-num;
        for(int i=0;i+k<cardPoints.size();i++){
            num-=cardPoints[i];
            num+=cardPoints[i+k];
            ans=max(ans,sum-num);
        }
        return ans;


    }
};
int main(){
    return 0;
}