#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int smallestNumber(int n) {
        int i=log2(n);
        return (int)pow(2,i+1)-1;
    }
};
int main(){
    return 0;
}