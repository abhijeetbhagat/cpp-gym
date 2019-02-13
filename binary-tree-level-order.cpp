
#include<vector>
#include<cassert>
#include "lest.hpp"
using namespace std;

struct TreeNode{
  TreeNode *left, *right;
  int val;
};

vector<vector<int>> levelOrder(TreeNode *root){
  if(root == nullptr) return {};
  vector<vector<TreeNode*>> M = {{root}};
  vector<vector<int>> _M = {{root->val}};
  int i = 0;
  while(true) {
    vector<TreeNode*> _v;
    vector<int>  _q;
    for(int j = 0; j < M[i].size(); j++){
      if(M[i][j]->left != nullptr) {
        _v.push_back(M[i][j]->left); 
        _q.push_back(M[i][j]->left->val);
      }
      if(M[i][j]->right != nullptr){
        _v.push_back(M[i][j]->right); 
        _q.push_back(M[i][j]->right->val);
      }     
    }
    if(_v.size() == 0)
      break;
    M.push_back(_v);
    _M.push_back(_q);
    i++;
  }

   return _M;
}

const lest::test tests[] = {
    CASE("2 height") {
      TreeNode *a = new TreeNode();
      a->val = 2;
      TreeNode *b = new TreeNode();
      b->val = 3;
      TreeNode *c = new TreeNode();
      c->val = 4;
      a->left = b;
      a->right = c;
      EXPECT(levelOrder(a).size() == 2); 
    },
    CASE("1 height") {
      TreeNode *a = new TreeNode();
      EXPECT(levelOrder(a).size() == 1); 
    }, 
    CASE("3 height") {
      TreeNode *a = new TreeNode();
      TreeNode *b = new TreeNode();
      TreeNode *c = new TreeNode();
      TreeNode *d = new TreeNode();
      a->left = b;
      a->right = c;
      b->left = d;
      EXPECT(levelOrder(a).size() == 3); 
    },
};

int main(int argc, char** argv){ 
  return lest::run(tests, argc, argv);
}

