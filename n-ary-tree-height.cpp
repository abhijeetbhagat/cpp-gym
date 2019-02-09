/*
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include<cassert>
#include<vector>
#include"lest.hpp "
using namespace std;
struct Node{
  vector<Node*> children;
};

int GetHeight(Node* n){
  if(n->children.empty()){
    return 1;
  }
  int max = 0;
  for(Node *c : n->children){
    auto h = GetHeight(c);
    if(h > max) {
      max = h;
    } 
  }
  return 1 + max;
}

const lest::test tests[] = {
    CASE("2 height") {
      Node *a = new Node();
      Node *b = new Node();
      Node *c = new Node();
      a->children.push_back(b);
      a->children.push_back(c);
      EXPECT(GetHeight(a) == 2); 
    },
    CASE("1 height") {
      Node *a = new Node();
      EXPECT(GetHeight(a) == 1); 
    }, 
    CASE("3 height") {
      Node *a = new Node();
      Node *b = new Node();
      Node *c = new Node();
      Node *d = new Node();
      a->children.push_back(b);
      a->children.push_back(c);
      b->children.push_back(d);
      EXPECT(GetHeight(a) == 3); 
    },
};

int main(int argc, char** argv){ 
  return lest::run(tests, argc, argv);
}

