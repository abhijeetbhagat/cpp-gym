#include<iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int _val) : val(_val), left(nullptr), right(nullptr){}
};

void inorder(TreeNode *node){
  if(node->left != nullptr){
    inorder(node->left);
  }
  std::cout << node->val << ' ';
  if(node->right != nullptr){
    inorder(node->right);
  }
}

int main(){
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->right = new TreeNode(5);
  inorder(root);
}
