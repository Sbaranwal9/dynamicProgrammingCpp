#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> bestSum(int n, std::vector<int> v, std::unordered_map<int, std::vector<int>> &m){
  if(m.find(n) != m.end()) return m[n];
  if(n == 0) return {};
  if(n < 0) return {-1};
  std::vector<int> ar = {-1};
  for(auto i : v){
    int r = n - i;
    std::vector<int> a = bestSum(r, v, m);
    if(a.empty() || (!a.empty() && a[0] != -1)){
      a.push_back(i);
      if((!ar.empty() && ar[0] == -1) || ar.size() > a.size()){
        ar = a;
      }
    }
  }
  m[n] = ar;
  return ar;
}

int main(){
  std::unordered_map<int, std::vector<int>> m;
  std::vector<int> a = bestSum(100, {1, 2, 5, 25}, m);
  for(auto i : a){
    std::cout << i << " ";
  }
  std::cout << std::endl;
}