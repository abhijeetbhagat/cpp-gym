/*
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:
If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
 
Example 1:
Input: "IDID"
Output: [0,4,1,3,2]
Example 2:
Input: "III"
Output: [0,1,2,3]
Example 3:
Input: "DDI"
Output: [3,2,0,1]
 */

#include<vector>
#include<cassert>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

int main(){ 
  std::string s= "DDI";
  std::vector<int> a(s.size() + 1);
  std::iota(a.begin(), a.end(), 0);
  do{
    bool found = true;
    for(int i = 0; i < s.size(); ++i){ 
      if(s[i] == 'I' && a[i] > a[i+1]) {
        found = false;
        break;
      }
      if(s[i] == 'D' && a[i] < a[i+1]) {
        found = false;
        break;
      }
    }
    if(found)
      break;

  }while(std::next_permutation(a.begin(), a.end()));
  assert(std::equal(a.begin(), a.end(), begin({3,2,0,1})));
}
