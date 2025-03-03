#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int  ans=events[0][0];
        int maxtime=events[0][1];
        for(int i=1;i<events.size();i++){
            int index=events[i][0];
            int time=events[i][1]-events[i-1][1];
            if(time>maxtime){
                ans=index;
                maxtime=time;
            }
            else if(time==maxtime){
                ans=min(ans,index);
            }
        }
        return ans;

    }
};
unsigned main(){
    return 0;
}