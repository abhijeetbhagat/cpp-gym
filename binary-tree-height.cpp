#include<cassert>
#include "lest.hpp"

struct Node {
  Node *left, *right;
};

int maxDepth(Node *r){
  if(r == nullptr) return 0;
  if(r->left == nullptr && r->right == nullptr) return 1;
  int max = -1;
  if(r->left){
    auto lh = maxDepth(r->left);
    if(lh > max)
      max = lh;
  }
  if(r->right){
    auto rh = maxDepth(r->right);
    if(rh > max)
      max = rh;
  }
  return 1+max;
}

const lest::test tests[] = {
    CASE("2 height") {
      Node *a = new Node();
      Node *b = new Node();
      Node *c = new Node();
      a->left = b;
      a->right = c;
      EXPECT(maxDepth(a) == 2); 
    },
    CASE("1 height") {
      Node *a = new Node();
      EXPECT(maxDepth(a) == 1); 
    }, 
    CASE("3 height") {
      Node *a = new Node();
      Node *b = new Node();
      Node *c = new Node();
      Node *d = new Node();
      a->left = b;
      a->right = c;
      b->left = d;
      EXPECT(maxDepth(a) == 3); 
    },
};

int main(int argc, char** argv){ 
  return lest::run(tests, argc, argv);
}

