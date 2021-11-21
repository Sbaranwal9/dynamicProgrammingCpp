#include <iostream>
#include <vector>
#include <unordered_map>

bool canSum(int n, std::vector<int> a, std::unordered_map<int, bool> &m){
  if(n == 0) return true;
  if(n < 0) return false;
  for(auto i : a){
    if(m.find(n-i) == m.end()) m[n-i] = canSum(n-i, a, m);
    if(m[n-i]) return true;
  }
  return false;
}

int main(){
  std::unordered_map<int, bool> m;
  std::cout << canSum(300, {7, 14}, m) << std::endl;
}