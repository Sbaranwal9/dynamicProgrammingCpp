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

std::vector<int> howSumTab(int target, std::vector<int> numbers){
  std::vector<std::vector<int>> a(target+1, std::vector<int>(1,-1));
  a[0] = {};
  for(int i = 0; i <= target; i++){
    if(a[i].empty() || (!a[i].empty() && a[i][0] != -1)){
      for(int j : numbers){
        if(i + j <= target){
          a[i + j] = std::vector<int> (a[i]);
          a[i+j].push_back(j);
        }
      }
    }
  }
  return a[target];
}

int main(){
  // std::unordered_map<int, std::vector<int>> m;
  // std::vector<int> v = howSum(300, {7, 15}, m);
  std::vector<int> v = howSumTab(300, {7, 15});
  for(auto i : v){
    std::cout << i << " ";
  }
  std::cout << std::endl;
}