#include<bits\stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    void dfs(TreeNode*root,int &n,int &ans){
        if(root==NULL)
        return;
        if(root->val!=n){
            if(ans==-1)
            ans=root->val;
            else
            ans=min(ans,root->val);
        }
        dfs(root->left,n,ans);
        dfs(root->right,n,ans);
        
    }
    int findSecondMinimumValue(TreeNode* root) {
        int ans=-1;
       dfs(root,root->val,ans);
       return ans;
    }
};
int main(){
    return 0;
}