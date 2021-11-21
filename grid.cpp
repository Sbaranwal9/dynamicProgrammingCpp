#include <iostream>
#include <unordered_map>

int grid(int m, int n, std::unordered_map<std::string, int> &h){
  if(m == 1 && n == 1) return 1;
  if(m == 0 || n == 0) return 0;
  std::string p = std::to_string(m)+','+ std::to_string(n);
  if(h.find(p) == h.end())
    h[p] = grid(m-1, n, h) + grid(m, n-1, h);
  return h[p];  
}

int main(){
  int m,n;
  std::cin >> m >> n;
  std::string p = std::to_string(m)+','+ std::to_string(n);
  std::cout << p << std::endl;
  std::unordered_map<std::string, int> h;
  std::cout << grid(m, n, h) << std::endl;
}