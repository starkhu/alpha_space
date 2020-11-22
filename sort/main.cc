#include<iostream>
#include "bubble_sort.h"
#include "insert_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "count_sort.h"
#include "radix_sort.h"

template <typename T>
void Checker(int len, void (*sort_function)(int* arr, int len)) {
  // generator random input
  int arr[len];
  for (int i = 0; i < len; i++)
    arr[i] = rand() %1000;
  auto print_array = [](const int* arr, const int len, std::string flag="") {
    std::cout << flag;
    for (int i=0; i < len; i++) {
      std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
  };
  print_array(arr, len, "before sorted, array: ");
  sort_function(arr, len);
  // QuickSort(arr, 0, 9);
  print_array(arr, len, "after sorted, array: ");
}

int main() {
  //Checker<int>(10, BubbleSort);
  //Checker<int>(10, BubbleSort2);

  //Checker<int>(10, InsertSort);
  
  //Checker<int>(10, InsertSort);

  // Checker<int>(5, MergeSort);

  // Checker<int>(10, HeapSort);

  // Checker<int>(30, CountSort);

  Checker<int>(30, RadixSort);


  
  return 0;
}
