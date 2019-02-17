class Solution {
  public:
    int hammingWeight(uint32_t n) {
      if(n == 0)
        return 0;
      if(n == 1 || (n&(n-1) == 0)) //check if power of 2
        return 1;
      int cnt = 0;
      for(uint32_t i = 0, mask = 1; i < 32; ++i){ 
        if(mask&n)cnt++;
        mask <<= 1;
      }  
      return cnt;
    }
};
