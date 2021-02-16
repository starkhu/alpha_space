#include<iostream>

int MaxSubsquenceSum(const int* arr, const int len) {
  if(arr == nullptr) return -1;
  if(len == 1) return *arr;
  
  int max_sum[len];
  int max_value = *arr;
  std::memset(max_sum, 0, sizeof(int)*len);
  max_sum[0] = *arr;
  for (int i = 1; i < len; ++i) {
    // max_sum[i] = std::max(max_sum[i-1]+arr[i], arr[i]);
    max_sum[i] = max_sum[i-1] > 0 ? max_sum[i-1]+arr[i] : arr[i];
    max_value = max_value > max_sum[i] ? max_value : max_sum[i];
  }
  return max_value;
}

int main() {
  int arr[7] = {-1, -2, 3, 6, 5, -1, 5};
  std::cout << "max sub_squence sum is: "
            << MaxSubsquenceSum(arr, 7)
	    << std::endl;
  return 0;
}
