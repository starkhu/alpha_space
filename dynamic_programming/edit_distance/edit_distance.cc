#include<iostream>
#include<string>

using std::string;

int MinOfThree (int n1, int n2, int n3) {
  int min = n1 < n2 ? n1 : n2;
  min = min < n3 ? min : n3;
  return min;
}


int EditDistance(const string src_str, const string dst_str){
  int src_len = src_str.size();
  int dst_len = dst_str.size();
  
  if (src_len == 0) return dst_len;
  if (dst_len == 0) return src_len;

  int distance = 0;
  int cost = src_str[src_len-1] == dst_str[dst_len-1] ? 0 : 1;
  distance = MinOfThree(EditDistance(src_str.substr(0, src_len-1), dst_str) + 1,
                        EditDistance(src_str, dst_str.substr(0, dst_len-1)) + 1,
     		          EditDistance(src_str.substr(0, src_len-1),
      		               dst_str.substr(0, dst_len-1)) + cost);
  return distance;
}

int EditDistanceFromBottom(const string src_str, const string dst_str) {
  const int src_len = src_str.size();
  const int dst_len = dst_str.size();
  if (src_len == 0) return dst_len;
  if (dst_len == 0) return src_len;
  int edit_distance[src_len+1][dst_len+1];
  for (int i=0; i<src_len+1; ++i) {
    edit_distance[0][i] = i;
  }
  for (int i=0; i<dst_len+1; ++i) {
    edit_distance[i][0] = i;
  }
  for (int row = 1; row<dst_len+1; ++row) {
    for (int col = 1; col < src_len+1; ++col) {
      int cost = src_str[row] == dst_str[col] ? 0 : 1;
      edit_distance[row][col] = MinOfThree(edit_distance[row-1][col]+1,
                                           edit_distance[row][col-1]+1,
					   edit_distance[row-1][col-1]+ cost);
    }
  }
  return edit_distance[src_len][dst_len];
}

int main() {
  string src_str = "appl";
  string dst_str = "aapble";
  std::cout << "edit_distance between appl and apply is: " << EditDistance(src_str, dst_str) << std::endl;
  std::cout << "edit_distance between appl and apply is: "
            << EditDistanceFromBottom(src_str, dst_str) << std::endl;
}
