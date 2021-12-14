// Question Link: https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameterOfBinaryTree(TreeNode* root) {
        int longestDiameter = 0;
        helper(root, longestDiameter);
        return longestDiameter;
    }
    
    int helper(TreeNode *cur, int &longestDiameter) {
        if (cur == NULL) {
            return 0;
        }
        int leftLongestPathLen = ((cur->left) ? 1 : 0) + helper(cur->left, longestDiameter);
        int rightLongestPathLen = ((cur->right) ? 1 : 0) + helper(cur->right, longestDiameter);
        longestDiameter = max(leftLongestPathLen + rightLongestPathLen, longestDiameter);
        return max(leftLongestPathLen, rightLongestPathLen);
    }
};