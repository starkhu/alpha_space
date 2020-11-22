#include<iostream>

template<typename T>
void QuickSort(T* arr, int low, int high) {
  // foolproof check
  if(low > high) {
    return;
  }

  T baseline = arr[low];
  int left = low;
  int right = high;
  while(left != right) {
    while(left < right && arr[right] >= baseline)
      right--;
    arr[left] = arr[right];
    while(left<right && arr[left] <= baseline)
      left++;
    arr[right] = arr[left];
  }
  arr[left] = baseline;
  QuickSort(arr, low, left-1);
  QuickSort(arr, right+1, high);
}


