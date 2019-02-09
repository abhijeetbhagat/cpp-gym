/*
 Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 */
class Solution {
  public:
    vector<int> sortArrayByParity(vector<int>& A) {
      vector<int> o(A.size());
      short f=0, j = A.size()-1;
      for(auto& i:A){
        o.at((i&1) == 0? f++:j--) = i;
      }
      return o;
    }
};
