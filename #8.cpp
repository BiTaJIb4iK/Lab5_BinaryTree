class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if (!root) {
            return result;
        }

        std::map<int, std::vector<int>> columnMap; 
        std::queue<std::pair<TreeNode*, int>> nodeQueue; 
        nodeQueue.push({root, 0}); 

        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();

            for (int i = 0; i < size; ++i) {
                auto [node, col] = nodeQueue.front();
                nodeQueue.pop();

                columnMap[col].push_back(node->val);

                if (node->left) {
                    nodeQueue.push({node->left, col - 1});
                }

                if (node->right) {
                    nodeQueue.push({node->right, col + 1});
                }
            }
        }

        for (auto& entry : columnMap) {
            result.push_back(entry.second);
        }

        return result;
    }
};