#include<iostream>

//status function: 前n个物品的最大价值
// 状态转移方程：

// 假设wi > w, 则f(i,W) = f(i-1, W)
// 如果wi <= W, 则第i个物品可以装进背包，此时f(i, W) = f(i-1, W-wi) + vi
//             也可以讲该物品不装进背包中，此时f(i,w) = f(i-1, w).取两者的较大值。


int ZeroOnePackage(int* weight, int* value, int len, int  package_weight) {
  if (len==0) return 0;
  int max_value[len+1][package_weight+1];
  std::memset(max_value, 0, sizeof(int)*(len+1)*(package_weight+1));
  
  for(int i=1; i<len+1; ++i) {  // item
    for(int w=1; w<package_weight+1; ++w) {  // weight
      if (weight[i-1] > w) {
        max_value[i][w] = max_value[i-1][w];
      } else {
        int include_item = max_value[i-1][w-weight[i-1]] + value[i-1];
	int exclude_item = max_value[i-1][w];
	max_value[i][w] = include_item > exclude_item ? include_item : exclude_item;
      }
    }
  }

  return max_value[len][package_weight];
}

int main() {
  const int num_packages = 4;
  int package_weights = 6;
  int item_values[num_packages] = {6,10,5,10};
  int item_weights[num_packages] = {3,1,2,4};
  std::cout << "0_1_package: "
            << ZeroOnePackage(item_weights, item_values, num_packages, package_weights)
            << std::endl;

  return 0;
}
