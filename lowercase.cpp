/*
 Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"
 */
#include<iostream>
#include<cassert>
#include<thread>
#include<chrono>
using namespace std;

class Solution {
  public:
    string toLowerCase(string str) {
      string output;
      output.reserve(str.size());
      for(auto &c : str) { 
        if (c >= 65 && c <= 90) { 
          output.push_back(c + 32);
        } else {
          output.push_back(c); 
        }
      }  
      return output;
    }
};
