class Solution {
public:
    int encode(TreeNode* root, int target, int depth, int parent) {
        if (!root) return 0;
        if (root->val == target) return (parent << 8) | depth;
        int left = encode(root->left, target, depth + 1, root->val);
        if (left) return left;
        return encode(root->right, target, depth + 1, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int xInfo = encode(root, x, 0, -1);
        int yInfo = encode(root, y, 0, -1);
        return ((xInfo & 255) == (yInfo & 255)) && ((xInfo >> 8) != (yInfo >> 8));
    }
};