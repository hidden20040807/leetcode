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
   
    vector<int> dfs(TreeNode*root){
        if(root==NULL){
            return{0,0};
        }
        int val1=0;
        vector<int>a1=dfs(root->left);
        vector<int>a2=dfs(root->right);
        val1+=max(a1[0],a1[1]);
        val1+=max(a2[0],a2[1]);
        int val2=root->val;
        val2+=a1[0];
        val2+=a2[0];
        return{val1,val2};
    }
    int rob(TreeNode* root) {
        vector<int>ans=dfs(root);
        return max(ans[0],ans[1]);
    }
};
int main(){
    return 0;
}