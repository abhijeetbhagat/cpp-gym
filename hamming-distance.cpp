#include<cassert>
#include<string>
#include<bitset>
using namespace std;

class Solution {
  public:
    int hammingDistance(int x, int y) {
      string s1 = std::bitset<32>(x).to_string();
      string s2 = std::bitset<32>(y).to_string();
      int cnt = 0;
      for(int i = 0; i < s1.size(); i++){  
        if(s1[i] != s2[i]) cnt++;
      } 
      return cnt;
    }
};
