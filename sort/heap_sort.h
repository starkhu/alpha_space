#include<iostream>

template<typename T>
void Swap(T* a, T* b) {
  T temp = *a;
  *a = *b;
  *b = temp;
}

// 
template <typename T>
void Heapify(T* arr, int start, int end) {
  int father = start;
  int son = 2 * start + 1;

  while (son <= end) {
    if (son+1<=end && arr[son] < arr[son+1]) ++son;

    if (arr[son] <= arr[father]) return;

    Swap(arr+son, arr+father);
    father = son;
    son = 2 * father + 1;
  }
}

template <typename T>
void HeapSort(T* arr, int len) {
  if (len<2) return;

  for (int i=(len-1)/2; i>=0; i--) Heapify(arr, i, len-1);

  for (int i=len-1; i>0; i--) {
    Swap(arr, arr+i);
    Heapify(arr, 0, i-1);
  }
}
