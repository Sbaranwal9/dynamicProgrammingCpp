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

std::vector<std::vector<std::string>> allConstructTab(std::string target, std::vector<std::string> wordBank){
  std::vector<std::vector<std::vector<std::string>>> a(target.length() + 1);
  std::vector<int> check(target.length() + 1, 0);
  check[0] = 1;
  a[0] = {{{""}}};
  for(int i = 0; i <= target.length(); i++){
    if(check[i] != 0){
      for(auto word : wordBank){
        if(i + word.length() <= target.length() && target.substr(i, word.length()).compare(word) == 0){
          check[i + word.length()] = 1;
          std::vector<std::vector<std::string>> c = a[i];
          for(auto j : c){
            j.push_back(word);
            a[i + word.length()].push_back(j);
          }
        }
      }
    }
  }
  return a[target.size()];
}

int main(){ 
  std::unordered_map<std::string, std::vector<std::vector<std::string>>> m;
  std::vector<std::vector<std::string>> v = allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}, m);
  // std::vector<std::vector<std::string>> v = allConstructTab("purple", {"purp", "p", "ur", "le", "purpl"});
  for(auto ar : v){
    for(auto a : ar){
      std::cout << a << " ";
    }
    std::cout << std::endl;
  }
}