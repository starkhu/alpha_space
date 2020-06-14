#include <iostream>

// 时间复杂度： O(mn)
// 空间复杂度： O(mn)
int robotMove(int m, int n) {
  if (m <= 0 || n <= 0) 
    return 0;
  
  int dp[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
  }

  return dp[m-1][n-1];
}

int main() {
  std::cout << "rebotMove(3, 7) is: " << robotMove(3, 7) << std::endl;
  return 0;
}
