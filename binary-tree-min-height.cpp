
#include<cassert>
#include<limits>
#include "lest.hpp"

struct Node {
  Node *left, *right;
};

int maxDepth(Node *r){
  if(r == nullptr) return 0;
  if(r->left == nullptr && r->right == nullptr) return 1;
  int min = std::numeric_limits<int>::max();
  if(r->left){
    auto lh = maxDepth(r->left);
    if(lh < min)
      min = lh;
  }
  if(r->right){
    auto rh = maxDepth(r->right);
    if(rh < min)
      min = rh;
  }
  return 1+min;
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
      EXPECT(maxDepth(a) == 2); 
    },
};

int main(int argc, char** argv){ 
  return lest::run(tests, argc, argv);
}

