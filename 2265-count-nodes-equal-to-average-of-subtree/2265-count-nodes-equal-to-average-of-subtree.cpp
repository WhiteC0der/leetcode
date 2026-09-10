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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right= solve(root->right);
        int sum = left.first+right.first + root->val;
        int count =left.second+right.second + 1;

        return {sum,count};
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = averageOfSubtree(root->left);
        int right = averageOfSubtree(root->right);

        pair<int,int> sumleft=solve(root->left);
        pair<int,int> sumright=solve(root->right);

        int sum=sumleft.first+sumright.first+root->val;
        int avg=sum/(sumleft.second+sumright.second+1);

        if(avg==root->val){
            return 1 + left + right;
        }

        return left + right;
    }
};