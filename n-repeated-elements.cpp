/*
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

 

Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5
 */

#include<map>
#include<cassert>
class Solution {
  public:
    int repeatedNTimes(vector<int>& A) {
      std::map<int, int> m;
      int mk , mv; mk = mv = -1;
      for(auto& i : A) {
        m[i]++; 
        if(mv < m[i]){
          mk = i;
          mv = m[i];
        }
      }
      return mk;
    }
};
