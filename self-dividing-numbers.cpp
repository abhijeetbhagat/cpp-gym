#include<vector>

class Solution {
  private:
    int numDigits(int num){
      return num < 10 ? 1 :
        num < 100 ? 2 :
        num < 1000 ? 3 :
        num < 10000 ? 4 : 5;
    }

  public:
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int> v;
      v.reserve(right - left);
      for(int i = left; i <= right; i++){
        auto n = numDigits(i);
        bool flag = true;
        int num = i;
        for(int j = 0; j < n; ++j){
          auto d = num%10;
          if(d == 0 || i%d != 0) { flag = false; break;}
          num = num / 10;
        }
        if(flag) v.push_back(i);
      }
      return v;
    }
};
