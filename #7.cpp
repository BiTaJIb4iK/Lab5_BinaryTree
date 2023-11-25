class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int result = 0;

        int state = cameraState(root, result);

        if (state == 0) {
            result++;
        }

        return result;
    }

private:
    int cameraState(TreeNode* node, int& result) {
        if (node == nullptr) {
            return 1;
        }

        int left = cameraState(node->left, result);
        int right = cameraState(node->right, result);

        if (left == 0 || right == 0) {
            result++;
            return 2;
        }

        if (left == 2 || right == 2) {
            return 1;
        }

        return 0;
    }
};