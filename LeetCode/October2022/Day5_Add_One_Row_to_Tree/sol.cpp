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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int d = 0 ;
        if(d == (depth -1)){
            TreeNode* new_node = new TreeNode(val) ;
            new_node->left = root ;
            root = new_node ;
            return root ;
        }
        queue<TreeNode*> q ;
        q.push(root) ;
        while(!q.empty()){
            int size = q.size() ;
            d++ ;
            for(int i=0;i<size;i++){
                TreeNode*curr = q.front() ;
                q.pop() ;
                if(!curr)
                    continue ;
                if(d == (depth - 1)){
                    TreeNode *new_node = new TreeNode(val) ;
                    TreeNode *new_node1 = new TreeNode(val) ;
                    if(curr->left){
                        TreeNode *temp = curr->left;
                        new_node->left = temp ;
                        curr->left = new_node ;
                    }
                    else{
                        curr->left = new_node;
                    }
                    if(curr->right){
                        TreeNode *temp = curr->right;
                        new_node1->right = temp ;
                        curr->right = new_node1 ;
                    }
                    else{
                        curr->right = new_node1;
                    }
                }  
                if(curr->left)
                    q.push(curr->left) ;
                if(curr->right)
                    q.push(curr->right) ;      
            }
            if(d == (depth-1))
                break ;
        }
        return root ;
    }
};
