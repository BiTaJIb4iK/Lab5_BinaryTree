class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        maxPathSumHelper(root, maxSum);

        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = std::max(0, maxPathSumHelper(root->left, maxSum));
        int rightSum = std::max(0, maxPathSumHelper(root->right, maxSum));

        maxSum = std::max(maxSum, leftSum + rightSum + root->val);

        return std::max(leftSum, rightSum) + root->val;
    }
};