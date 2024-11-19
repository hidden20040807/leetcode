#include<bits\stdc++.h>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    unordered_map<int,Employee*>hash;
    int dfs(vector<Employee*> &employees,int id){
        Employee* e=hash[id];
        int ans=e->importance;
        if(e->subordinates.size()){
            for(int i=0;i<e->subordinates.size();i++){
                ans+=dfs(employees,e->subordinates[i]);
            }
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(int i=0;i<employees.size();i++){
            hash.emplace(employees[i]->id,employees[i]);
        }
        return dfs(employees,id);
    }
};
int main(){
    return 0;
}