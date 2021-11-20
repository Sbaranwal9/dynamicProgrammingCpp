#include <iostream>
#include <unordered_map>

int fib(int n, std::unordered_map<int, int> &m){
  if(n <= 2) return 1;
  if(m.find(n) == m.end()){
    m[n] = fib(n-1, m)+fib(n-2, m);
  }
  return m[n];
}

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<int, int> m;
  std::cout << fib(n, m) << std::endl;
} 