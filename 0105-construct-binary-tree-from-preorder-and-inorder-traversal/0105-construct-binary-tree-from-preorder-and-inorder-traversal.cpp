/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(int val, vector<int>& inorder, int left, int right) {
        for (int i = left; i <= right; i++) {   // FIX: use <=
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, int& preidx) {
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preidx]);
        int idx = search(root->val, inorder, left, right);
        preidx++;

        root->left  = helper(preorder, inorder, left, idx - 1, preidx);
        root->right = helper(preorder, inorder, idx + 1, right, preidx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        return helper(preorder, inorder, 0, preorder.size() - 1, preidx);  
    }
};
