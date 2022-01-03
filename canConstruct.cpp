#include <iostream>
#include <vector>
#include <unordered_map>

bool canConstruct(std::string target, std::vector<std::string> wordBank, std::unordered_map<std::string, bool> &m){
  if(m.find(target) != m.end()) return m[target];
  if(target.compare("") == 0) return true;
  for(std::string s : wordBank){
    if(target.find(s) == 0){
      std::string rem = target.substr(s.length());
      if(canConstruct(rem, wordBank, m)) {
        m[target] = true;
        return true;
      }
    }
  }
  m[target] = false;
  return false;
}

int main(){
  std::unordered_map<std::string, bool> m;
  std::cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, m) << std::endl;
}