#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int n:stones){
            pq.push(n);
        }

        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            if(pq.empty())
            return a;
            int b=pq.top();
            pq.pop();
            if(a>b){
                pq.push(a-b);
            }
        }
        return 0;
    
    }
};
int main(){
   
    return 0;
}