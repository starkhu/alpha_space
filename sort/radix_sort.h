#include<iostream>
#include<string>

void _radixsort(int* arr, int len, int iexp) {
  int result_arr[len];
  int cnt_arr[10];

  memset(cnt_arr, 0, sizeof(int)*10);

  for (int i=0; i<len; i++) {
    cnt_arr[(arr[i]/iexp)%10]++;
  }
  for (int i=1; i<10; i++) {
    cnt_arr[i] += cnt_arr[i-1];
  }

  for (int i=len-1; i>=0; i--) {
    int radix = arr[i]/iexp%10;
    result_arr[cnt_arr[radix]-1] = arr[i];
    cnt_arr[radix]--;
  }

  memcpy(arr, result_arr, sizeof(int)*len);
}

int arrmax(int* arr, int len) {
  int max = *arr;
  for (int i=0; i<len; i++) {
    if (*(arr+i) > max) max = *(arr+i);
  }
  return max;
}

void RadixSort(int* arr, int len) {
  int max = arrmax(arr, len);

  for (int iexp = 1; iexp<max; iexp*=10) {
    _radixsort(arr, len, iexp);
  }

}
