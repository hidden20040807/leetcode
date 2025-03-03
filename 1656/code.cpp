#include<bits\stdc++.h>
using namespace std;
class OrderedStream {
    public:
    int ptr;
    vector<string>q;
        OrderedStream(int n) {
            ptr=1;
            q.resize(1001,"");
        }
        
        vector<string> insert(int idKey, string value) {
            vector<string>ans;
            q[idKey]=value;
            if(q[ptr]!=""){
                int i;
                for(i=0;q[ptr+i]!="";i++){
                    ans.push_back(q[ptr+i]);
                }
                ptr=ptr+i;
                
            }
            return ans;
        }
    };
int main(){
    return 0;
}