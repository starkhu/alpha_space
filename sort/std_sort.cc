#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <vector>

int main () {
  int a[10];
  srand((unsigned)time(NULL));
  for (int i=0; i<10; i++) {
    a[i] = rand() % 100;
  }
  
  for(int i=0; i <10; i++) {
  std::cout << a[i] << " ";
  }
  std::cout << std::endl;
 
  // ascending order
  std::sort(a, a+10);
  for(int i=0; i <10; i++) {
  std::cout << a[i] << " ";
  }
  std::cout << std::endl;

  // descending order
  std::sort(a, a+10, [](const int& a, const int& b){return a >b ? a : b;});
  for(int i=0; i <10; i++) {
  std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  
  return 0;
}



