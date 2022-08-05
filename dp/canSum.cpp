#include <iostream>
#include <vector>
#include <unordered_map>

bool canSum(int n, std::vector<int> a, std::unordered_map<int, bool> &m){
  if(m.find(n) != m.end()) return m[n];
  if(n == 0) return true;
  if(n < 0) return false;
  for(auto i : a){
    if(canSum(n-i, a, m)){
      m[n] = true;
      return true;
    }
  }
  m[n] = false;
  return false;
}

bool canSumTab(int target, std::vector<int> numbers){
  std::vector<bool> a(target+1, false);
  a[0] = true;
  for(int i = 0; i <= target; i++){
    if(a[i] == true){
      for(int j : numbers){
        if(i + j <= target){
          a[i + j] = true;
        }
      }
    }
  }
  return a[target];
}

int main(){
  // std::unordered_map<int, bool> m;
  // std::cout << canSum(300, {7, 15}, m) << std::endl;
  std::cout << (canSumTab(300, {7, 15}) ? "true" : "false") << std::endl;
}