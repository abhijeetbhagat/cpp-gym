#include<cassert>
#include<vector>
#include<string>
#include<set>

using namespace std;

int minDeletionSize(vector<string>& A) { 
  auto c = A[0];
  set<int> s;

  for(int k = 1; k < A.size(); ++k){
    for(int i = 0; i < A[k].size(); i++){
      if(A[k][i] < c[i]) 
        s.insert(i);
    }
    if(s.size() == c.size()) 
      break; 
    c = A[k];
  }
  return s.size(); 
}

int main(){
  vector<string> v = {"egguij","gjsnnk","lstgon","ztzrqv"};
  assert(minDeletionSize(v) == 1);
  v = {"cba","daf","ghi"};
  assert(minDeletionSize(v) == 1);

  v = {"a","b"};
  assert(minDeletionSize(v) == 0);
  v = {"zyx","wvu","tsr"};
  assert(minDeletionSize(v) == 3);
}
