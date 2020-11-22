#include<iostream>

static void print_array(const int* arr,
                        const int len,
       	                std::string flag="") {
  std::cout << flag;
  for (int i=0; i < len; i++) {
    std::cout << arr[i] << "  ";
  }
  std::cout << std::endl;
}
template <typename T>
void MergeSort(T* arr, int len) {
  if (len < 2) return;

  T* aa = arr;
  int* bb = (T*)malloc(len * sizeof(T));
  std::memset(bb, 0, sizeof(int)*len);

  int iseg = 1;
  int istart = 0;
  for (iseg=1; iseg<len; iseg*=2) {
    for (istart=0; istart<len; istart+=iseg*2) {
      int imin = istart;
      int imid = std::min(istart+iseg, len);
      int imax = std::min(istart+2*iseg, len);

      int ii = imin;
      int istart1 = imin, iend1 = imid;
      int istart2 = imid, iend2 = imax;

      std::cout << "iseg, istart: " << iseg << " " << istart
                << ", imin, imid, imax: " << imin << " " << imid << " " << imax
		<< ", ii, istart1, iend1: " << ii << " " << istart1 << " " << iend1
		<< ", istart2, iend2: " << istart2 << " " << iend2
		<< std::endl;
      while ((istart1<iend1) && (istart2<iend2)) {
        //std::cout << "**1" << std::endl;
        bb[ii++] = aa[istart1] < aa[istart2] ? aa[istart1++] : aa[istart2++];
        //std::cout << "**2" << std::endl;
      }
      print_array(bb, len, "**1**: ");

      while (istart1<iend1) bb[ii++] = aa[istart1++];
      print_array(bb, len, "**2**: ");

      while (istart2<iend2) bb[ii++] = aa[istart2++];
      print_array(bb, len, "**3**: ");
      
    }
    int * ptmp = aa; aa = bb; bb = ptmp;
  }

  if (aa != arr) {
    std::memcpy(arr, aa, len*sizeof(T));
    bb = aa;
  }
  free(bb);
}
