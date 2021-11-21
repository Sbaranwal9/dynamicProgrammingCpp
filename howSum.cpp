#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> howSum(int n, std::vector<int> v, std::unordered_map<int, std::vector<int>> &m){
  if(m.find(n) != m.end()) return m[n];
  if(n == 0) return {};
  if(n < 0) return {-1};
  for(auto i : v){
    int r = n - i;
    std::vector<int> a = howSum(r, v, m);
    if(a.empty() || (!a.empty() && a[0] != -1)) {
      a.push_back(i);
      m[n] = a;
      return m[n];
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