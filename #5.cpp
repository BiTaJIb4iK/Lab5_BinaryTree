class Codec {
public:
    std::string serialize(TreeNode* root) {
        std::ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    TreeNode* deserialize(std::string data) {
        std::istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* root, std::ostringstream& out) {
        if (root == nullptr) {
            out << "null ";
            return;
        }

        out << root->val << ' ';
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    TreeNode* deserializeHelper(std::istringstream& in) {
        std::string val;
        in >> val;

        if (val == "null") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(std::stoi(val));
        root->left = deserializeHelper(in);
        root->right = deserializeHelper(in);

        return root;
    }
};