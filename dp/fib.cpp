#include <iostream>
#include <vector>
#include <unordered_map>

int fib(int n, std::unordered_map<int, int> &m){
  if(m.find(n) != m.end()) return m[n];
  if(n <= 2) return 1;
  m[n] = fib(n-1, m)+fib(n-2, m);
  return m[n];
}

int fibTab(int n){
  std::vector<int> a(n+1, 0);
  a[1] = 1;
  for(int i=2; i <= n; i++){
    a[i] = a[i-1] + a[i-2];
  }
  return a[n];
}

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<int, int> m;
  // std::cout << fib(n, m) << std::endl;
  std::cout << fibTab(n) << std::endl;
} 