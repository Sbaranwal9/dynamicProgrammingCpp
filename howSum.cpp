#include <iostream>
#include <vector>

std::vector<int> howSum(int n, std::vector<int> v){
  if(n == 0) return {};
  if(n < 0) return {-1};
  for(auto i : v){
    int r = n - i;
    std::vector<int> a = howSum(r, v);
    if(a.empty() || (!a.empty() && a[0] != -1)) {
      a.push_back(i);
      return a;
    }
  }
  return {-1};  
}

int main(){
  std::vector<int> v = howSum(7, {5, 3, 4, 7});
  for(auto i : v){
    std::cout << i << " ";
  }
  std::cout << std::endl;
}