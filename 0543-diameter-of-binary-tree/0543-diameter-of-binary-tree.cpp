class Solution {
public:
    struct Info {
        int d, h;
        Info(int dia, int height) {
            d = dia;
            h = height;
        }
    };

    Info diameter(TreeNode* root) {
        if (!root) return Info(0, 0); // \U0001f9f1 Base: empty node

        Info l = diameter(root->left);
        Info r = diameter(root->right);

        int finalDia = max({l.d, r.d, l.h + r.h + 1}); // \U0001f9ee Longest path at node
        int finalHeight = max(l.h, r.h) + 1;           // \U0001f4cf Current height

        return Info(finalDia, finalHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).d - 1; // \U0001f53b Convert to edge count
    }
};