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

std::vector<int> bestSumTab(int target, std::vector<int> numbers){
  std::vector<std::vector<int>> a(target+1, std::vector<int> (1,-1));
  a[0] = {};
  for(int i = 0; i <= target; i++){
    if(a[i].empty() || (!a[i].empty() && a[i][0] != -1)){
      for(int j : numbers){
        if(i + j <= target){
          std::vector<int> c(a[i]);
          c.push_back(j);
          if((!a[i + j].empty() && a[i + j][0] == -1) || c.size() < a[i + j].size()){
            a[i + j] = c;
          }
        }
      }
    }
  }
  return a[target]; 
}

int main(){
  // std::unordered_map<int, std::vector<int>> m;
  // std::vector<int> a = bestSum(100, {1, 2, 5, 25}, m);
  std::vector<int> a = bestSumTab(100, {1, 2, 5, 25});
  for(auto i : a){
    std::cout << i << " ";
  }
  std::cout << std::endl;
}