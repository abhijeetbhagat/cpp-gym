#include<vector>
#include<cassert> 
#include<algorithm>
#include<iostream>
using namespace std;

int Partition(vector<int>& A, int p, int r){ 
  int i = p-1;
  int x = A[r]; 
  for(int j = p; j < r; ++j){
    if(A[j] < x){
      i = i + 1;
      std::swap(A[i], A[j]);
    }
  }

  std::swap(A[i+1], A[r]);
  return i+1;
}

void QuickSort(vector<int>& A, int p, int q){ 
  if(p < q){
    int i = Partition(A, p, q);
    QuickSort(A, p, i-1);
    QuickSort(A, i+1, q);
  }
}

int main(){ 
  vector<int> v = {5,4,3,2,1};
  QuickSort(v, 0, v.size() -1);
  assert(std::equal(v.begin(), v.end(), begin({1,2,3,4,5})));
}
