class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        travel(root, result);
        return result;
    }
private:
    void travel(TreeNode* root, std::vector<int>& result){
        if(!root)
            return;
        else result.push_back(root->val);

        travel(root->left, result);
        travel(root->right, result);
    }
};