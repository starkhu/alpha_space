#include<iostream>

template<typename T>
void BubbleSort(T* arr, int len) {
  // foolproof check
  if(len <  2)
    return;

  // bubble sort
  for(int i = 0; i < len; i++) {
    int sorted = 1;
    for(int j = 0; j < len-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        //swap
	sorted = 0;
        T temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
      }
    }
    if (sorted == 1)
     break;
  }
}

template <typename T>
void BubbleSort2(T* arr, int len) {
  // foolproof check
  if (len < 2) {
    return;
  }

  // bubble sort by recursion
  for (int i=0; i < len-1; i++) {
    if(arr[i] > arr[i+1]) {
      //swap
      T temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
    }
  }

  BubbleSort2(arr, len-1);
}

