class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q || !p)
            return q==p;
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};