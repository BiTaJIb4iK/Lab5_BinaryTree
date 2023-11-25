class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> nodeStack;
        TreeNode* current = root;

        while (current != nullptr || !nodeStack.empty()) {
            while (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            }

            current = nodeStack.top();
            nodeStack.pop();

            if (--k == 0) {
                return current->val;
            }

            current = current->right;
        }

        return -1;
    }
private:
};