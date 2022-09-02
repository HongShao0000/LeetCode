/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        TreeNode* p = root;

        while(!s.empty()||p!=nullptr){
            while(p->left!=nullptr){
                s.push(p);
                p = p->left;
            }
            //没有左孩子就直接输出结果
            result.push_back(p->val);
            //cout<<p->val<<" ";
            //右孩子空时一直出栈，否则输出
            while(!s.empty()&&p->right==nullptr){
                p = s.top();
                result.push_back(p->val);
                //cout<<p->val<<" ";
                s.pop();
            }
            //如果有右孩子就指向右孩子
            p = p->right;
        }
        //for(int i = 0 ;i<result.size();i++){
        //    cout<<result[i]<<" ";
        //}
        return result;
    }
};