#include <iostream>

// 时间复杂度：O(n)
// 空间复杂度：O(1)
int fabonacci(const int& n) {
  if (n <= 0) {
    return 0;
  }
  if (n == 1 || n == 2) {
    return 1;
  }
  long long record[2] = {1, 1};
  int flag = 0;
  for (int i = 3; i <= n; i++) {
    record[flag%2] = record[0] + record[1];
    flag++;
  }
  if (n % 2 == 0) {
    return record[1];
  } else {
    return record[0];
  }
}

int main() {
  // std::cout << "f(10) is: " << fabonacci(10) << std::endl;
  // std::cout << "f(48) is: " << fabonacci(48) << std::endl;
  std::cout << "c(3) is: " << climbStairs(3) << std::endl;
  return 0;
}
