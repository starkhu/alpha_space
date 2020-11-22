#include<iostream>

template<typename T>
void InsertSort(T* arr, int len){
  // foolproof check
  if(len < 2)
    return;

  //insert sort
  for(int i=1; i<len; i++) {
   int j = i-1;
   const T temp = arr[i];
   while(temp < arr[j]) {
     arr[j+1] = arr[j];
     j--;
   }
   arr[j+1] = temp;
  }
}
