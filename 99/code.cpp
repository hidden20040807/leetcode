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
    TreeNode* ahead=NULL;
    TreeNode* next=NULL;
    TreeNode* cur=NULL;
    TreeNode* p1=NULL;
    TreeNode* p2=NULL;
    bool flag=false;
    void dfs(TreeNode *root){
        if(root==NULL)
        return;
        dfs(root->left);
        ahead=cur;
        cur=next;
        next=root;
        if(flag){
            if(ahead!=NULL){
                if(cur->val<ahead->val){
                p2=cur;
                }
            }
        }
        else{
            if(cur!=NULL){
                if(cur->val>next->val){
                    p1=cur;
                    flag=true;
                }
            }
        }
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        ahead=cur;
        cur=next;
        if(flag){
            if(ahead!=NULL){
                if(cur->val<ahead->val){
                p2=cur;
                }
            }
        }
        else{
            if(cur!=NULL){
                if(cur->val>next->val){
                    p1=cur;
                    flag=true;
                }
            }
        }
        swap(p1->val,p2->val);
    }
    

};
int main(){
    return 0;
}