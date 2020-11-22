#include<iostream>

template <typename T>
void CountSort(T* arr, int len) {
  int min = *arr;
  int max = *arr;

  for (int i=0; i<len; i++) {
    if (arr[i] < min) {
      min = arr[i];
      continue;
    } else if (arr[i] > max) {
      max = arr[i];
      continue;
    }
  }
  
  int range = max-min+1;
  int* temp_arr = new int[range];
  memset(temp_arr, 0, sizeof(T)*range);

  for (int i=0; i<len; i++) {
    temp_arr[arr[i]-min]++;
  }

  int count=0;
  for (int i=0; i<range; i++) {
    for (int j = 0; j<temp_arr[i]; j++) {
      arr[count++] = min+i;
    }
  }
}
