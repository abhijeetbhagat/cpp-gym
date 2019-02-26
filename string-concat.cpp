#include<string>
#include<cassert>
using namespace std;

int main(){ 
  string s = "russ (ai) (edocn) cup";
  string result = "";

  for(int i = 0; i < s.size(); ++i){ 
    if(s[i] == ' ') continue;
    if(s[i] == '('){
      auto pos = s.find(')', i);
      for(int j = pos-1; s[j] != '('; j--){
        result.push_back(s[j]);
      }
      i = pos;
      continue;
    }
    result.push_back(s[i]);
  }

  assert(result == "russiancodecup");
}

