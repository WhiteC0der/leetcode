/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        // Morris Inorder Travelsal
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                if (prev != NULL) {
                    if (prev->val > curr->val) {
                        if (first == NULL) {
                            first = prev;
                        }
                        second = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode* IP = curr->left;
                while (IP->right != curr && IP->right != NULL) {
                    IP = IP->right;
                }
                if (IP->right != NULL) {
                    IP->right = NULL;
                    if (prev != NULL) {
                        if (prev->val > curr->val) {
                            if (first == NULL) {
                                first = prev;
                            }
                            second = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                } else {
                    IP->right = curr;
                    curr = curr->left;
                }
            }
        }

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};