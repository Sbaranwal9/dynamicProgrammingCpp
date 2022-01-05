#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<std::string>> allConstruct(std::string target, std::vector<std::string> wordBank,  std::unordered_map<std::string, std::vector<std::vector<std::string>>> &m){
  if(m.find(target) != m.end()) return m[target];
  if(target.compare("") == 0) return {{}};
  std::vector<std::vector<std::string>> v;
  for(std::string s : wordBank){
    if(target.find(s) == 0){
      std::string rem = target.substr(s.length());
      std::vector<std::vector<std::string>> arr = allConstruct(rem, wordBank, m);
      for(auto &a : arr){
        a.insert(a.begin(),s);
      }
      v.insert(v.end(),arr.begin(),arr.end());
    }
  }
  m[target] = v;
  return v;
}

int main(){ 
  std::unordered_map<std::string, std::vector<std::vector<std::string>>> m;
  std::vector<std::vector<std::string>> v = allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}, m);
  for(auto ar : v){
    for(auto a : ar){
      std::cout << a << " ";
    }
    std::cout << std::endl;
  }
}