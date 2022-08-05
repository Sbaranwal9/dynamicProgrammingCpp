#include <iostream>
#include <vector>
#include <unordered_map>

int grid(int m, int n, std::unordered_map<std::string, int> &h){
  std::string p = std::to_string(m)+','+ std::to_string(n);
  if(h.find(p) != h.end()) return h[p];  
  if(m == 1 && n == 1) return 1;
  if(m == 0 || n == 0) return 0;
  h[p] = grid(m-1, n, h) + grid(m, n-1, h);
  return h[p];  
}

int gridTab(int m, int n){
  std::vector<std::vector<int>> a(m+1, std::vector<int> (n+1, 0));
  a[1][1] = 1;
  for(int i=0; i <= m; i++){
    for(int j=0; j <= n; j++){
      if(i+1 <= m) a[i+1][j] += a[i][j];
      if(j+1 <= n) a[i][j+1] += a[i][j];
    }
  }
  return a[m][n];
}

int main(){
  int m,n;
  std::cin >> m >> n;
  std::string p = std::to_string(m)+','+ std::to_string(n);
  std::cout << p << std::endl;
  std::unordered_map<std::string, int> h;
  // std::cout << grid(m, n, h) << std::endl;
  std::cout << gridTab(m, n) << std::endl;
}