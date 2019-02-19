/*
 Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
  public:
    void mergeTrees(TreeNode *node, TreeNode *t1, TreeNode *t2){

      if(t1 == nullptr && t2 == nullptr) return nullptr;
      if(t1 != nullptr && t1->left != nullptr){
        mergeTrees(t1->left, t2 != nullptr ? t2->left : nullptr);
      }
      if(t2 != nullptr ){
        if(t1 == nullptr)
          t1 = new TreeNode(0);
        if(t2->left != nullptr && t1->left == nullptr)
          t1->left = t2->left;
      }
      t1->val += (t2 != nullptr ? t2->val : 0);
      if(t1 != nullptr && t1->right != nullptr){
        mergeTrees(t1->right, t2 != nullptr ? t2->right : nullptr);
      }
      if(t2 != nullptr && t2->right != nullptr ){
        if(t1 == nullptr)
          t1 = new TreeNode(0);
        if(t1->right == nullptr)
          t1->right = t2->right;
      }
      return t1;
    }
};
