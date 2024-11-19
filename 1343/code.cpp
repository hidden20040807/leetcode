#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double sum=0;
        int ans=0;
        int left=0;
        for(int i=0;i<left+k;i++){
            sum+=arr[i];
        }
        if(sum/k>=threshold)
        ans++;
        while(left+k<arr.size()){
            sum+=arr[left+k];
            sum-=arr[left];
            left++;
             if(sum/k>=threshold)
        ans++;
        }
        return ans;
    }
};
int main(){
    return 0;
}