#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> howSum(int n, std::vector<int> v, std::unordered_map<int, std::vector<int>> &m){
  if(n == 0) return {};
  if(n < 0) return {-1};
  for(auto i : v){
    int r = n - i;
    if(m.find(r) == m.end()){
      m[r] = howSum(r, v, m);
    }
    if(m[r].empty() || (!m[r].empty() && m[r][0] != -1)) {
      m[r].push_back(i);
      return m[r];
    }
  }
  return {-1};  
}

int main(){
  std::unordered_map<int, std::vector<int>> m;
  std::vector<int> v = howSum(300, {7, 15}, m);
  for(auto i : v){
    std::cout << i << " ";
  }
  std::cout << std::endl;
}