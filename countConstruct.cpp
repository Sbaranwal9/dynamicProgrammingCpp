#include <iostream>
#include <vector>
#include <unordered_map>

int countConstruct(std::string target, std::vector<std::string> wordBank, std::unordered_map<std::string, int> &m){
  if(m.find(target) != m.end()) return m[target];
  if(target.compare("") == 0) return 1;
  int tot = 0;
  for(std::string word : wordBank){
    if(target.find(word) == 0){
      std::string rem = target.substr(word.length());
      tot += countConstruct(rem, wordBank, m);
    }
  }
  m[target] = tot;
  return tot;
}

int countConstructTab(std::string target, std::vector<std::string> wordBank){
  std::vector<int> a(target.length() + 1, 0);
  a[0] = 1;
  for(int i = 0; i <= target.length(); i++){
    if(a[i] >= 1){
      for(auto word : wordBank){
        if(i + word.length() <= target.length() && target.substr(i, word.length()).compare(word) == 0){
          a[i + word.length()] += a[i]; 
        }
      }
    }
  }
  return a[target.length()];
}

int main(){
  // std::unordered_map<std::string, int> m;
  // std::cout << countConstruct("purple",{"purp", "p", "ur", "le", "purpl"}, m) << std::endl;
   std::cout << countConstructTab("purple",{"purp", "p", "ur", "le", "purpl"}) << std::endl;
}