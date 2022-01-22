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

bool canConstructTab(std::string target, std::vector<std::string> wordBank){
  std::vector<bool> a (target.length() + 1, false);
  a[0] = true;
  for(int i = 0; i <= target.length(); i++){
    if(a[i] == true){
      for(auto word : wordBank){
        if(i + word.length() <= target.length() && target.substr(i, word.length()).compare(word) == 0){
          a[i + word.length()] = true;
        }
      }
    }
  }
  return a[target.length()];
}

int main(){
  // bool b = canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, m);
  bool b = canConstructTab("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"});
  std::cout << (b ? "true" : "false") << std::endl;
}