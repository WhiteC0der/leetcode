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
    TreeNode* node(int n,unordered_map<int,TreeNode*>& mpp){
        if(mpp.find(n)!=mpp.end()){
            return mpp[n];
        }

        return mpp[n] = new TreeNode(n);
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mpp;
        set<int> st;
        for(auto &temp : descriptions){
            int par= temp[0];
            int child =temp[1];
            st.insert(child);
            if(temp[2]){
                node(par,mpp)->left=node(child,mpp);
            }else{
                node(par,mpp)->right=node(child,mpp);
            }
        }

        for(int i=0;i<descriptions.size();i++){
            if(!st.count(descriptions[i][0])) return mpp[descriptions[i][0]];
        }

        return NULL;
    }
};