/*
   Given two strings representing two complex numbers.

   You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

   Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
*/

#include<string>
#include<cassert>

struct Complex{
  int a;
  int b;
  Complex(int a, int b):a(a), b(b){} 
  Complex operator*(Complex const& rhs){
    Complex result(0, 0);
    result.a = this->a * rhs.a +  this->b * rhs.b * -1;
    result.b = this->a * rhs.b + this->b * rhs.a; 
    return result;
  }
};

std::ostream& operator<<(std::ostream & out, const Complex& obj){
  std::string sign = (obj.b < 0 ? "-" : "");
  out << obj.a << '+' << sign << obj.b << 'i' << '\n';
  return out;
}

int parse_num(int i, const std::string& str, int& out){
  int num = 0;
  std::string str_num = "";
  while((str[i] != '+' && str[i] != 'i') && str[i] != '\0'){ 
    str_num += str[i++];
  } 
  out = std::stoi(str_num);
  return i;
}

Complex parse(std::string str){
  Complex c(0, 0);
  int k = 0, out = 0;
  for(int i = 0; i < str.size(); ++i){
    switch(str[i]){
      case '-':
        k = parse_num(i+1, str, out);
        out = 0 - out;
        if(str[k] == 'i') 
          c.b = out;
        else
          c.a = out;
        i = k;
        break; 
      case '+':
        i++;
      default:
        k = parse_num(i, str, out);
        if(str[k] == 'i') 
          c.b = out;
        else
          c.a = out;
        i = k;
    }
    out = 0;
  }
  return c;
}

class Solution {
  public:
    std::string complexNumberMultiply(std::string a, std::string b){ 
      Complex _a(parse(a));
      Complex _b(parse(b));
      auto r = _a * _b;
      return std::to_string(r.a) + '+' + std::to_string(r.b) + 'i';
    }
};

int main(){
  //assert(complexNumberMultiply("1+1i", "1+1i"));
  int out = 0;
  assert(parse("11+3i").a == 11);
  assert(parse("-11+35i").a == -11);
  assert(parse("-11+-35i").b == -35);
  assert(parse("1+3i").b == 3);
  assert(complexNumberMultiply("1+1i", "1+1i") == "0+2i");
  assert(complexNumberMultiply("1+-1i", "1+-1i") == "0+-2i");
}

