class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return checkMirror(root->left, root->right);
    }
private:
    bool checkMirror(TreeNode* l, TreeNode* r){
        if(!l || !r)
            return l==r;
        return (l->val == r->val) &&
           checkMirror(l->left, r->right) &&
           checkMirror(l->right, r->left);
    }
};