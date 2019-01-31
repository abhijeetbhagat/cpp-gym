#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

#define parent(i) (i-1)/2
#define left(i)   2*i+1
#define right(i)  2*i+2

void insert(std::vector<int> & v, int k){
  v.push_back(k);
  int i = v.size() - 1;
  while(i != 0 && v[i] < v[parent(i)]) {
    std::swap(v[i], v[parent(i)]);
    i = parent(i);
  }
}

int main(){
  std::vector<int> v;
  v.reserve(5);
  v.push_back(3);
  v.push_back(5);
  insert(v, 2); 
  assert(v.back() == 3);
}
