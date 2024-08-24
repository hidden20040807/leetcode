#include<bits\stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  //这道题需要观察，节点的颜色只和该节点最后一一次操作有关，所以倒叙遍历，
 // 使用set存储节点的值，利用lower_bound获取大于该值的最小的节点，
  //然后删除一直到lower_bound的值大于ops[i][2]这样把最后一次操作的节点删除，下面进行操作的时候就不会有影响
  //删除的时候如果是红色把答案++即可
class Solution {
public:
    set<int>nums;
   
    void make_nums(TreeNode*root){
        if(root==NULL)
        return;
        make_nums(root->left);
        nums.emplace(root->val);
        make_nums(root->right);
    }

    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
            make_nums(root);
            int ans=0;
            for(int i=ops.size()-1;i>=0;i--){
                while(true){
                    auto it=nums.lower_bound(ops[i][1]);
                    if(it==nums.end()||(*it)>ops[i][2])
                    break;
                    nums.erase(it);
                    if(ops[i][0])
                    ans++;
                }
                if(!nums.empty())
                break;
            }
            return ans;
    }
};
int main(){
    return 0;
}