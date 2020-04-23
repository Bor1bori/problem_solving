/**
 *
 * Title : K번째 수
 * Date  : 2020-04-23
 * URL   : https://www.acmicpc.net/problem/11004
 * Tags  : sort, mergesort
 *
 **/

#include <iostream>

using namespace std;


void merge(int list[8], int begin, int mid, int end) {
  int *sorted = static_cast<int *>(malloc(sizeof(int) * (end - begin)));
  int leftP = begin, rightP = mid;

  for (int i = 0 ; i < (end - begin) ; i ++) {
    if ((leftP != mid && list[leftP] < list[rightP]) || rightP == end) {
      sorted[i] = list[leftP++];
    } else {
      sorted[i] = list[rightP++];
    }
  }
  for (int i = begin ; i < end ; i ++) {
    list[i] = sorted[i - begin];
  }
  free(sorted);
  return;
}

void mergeSort(int list[8], int begin, int end) {
  int mid;

  if (end != (begin + 1)) {
    mid = (begin + end) / 2;
    mergeSort(list, begin, mid); // begin 부터 mid 전까지
    mergeSort(list, mid, end); // mid부터 end 전까지
    merge(list, begin, mid, end);
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  int *list;
  int i, tmp;

  cin >> n >> k;
  list = static_cast<int *>(malloc(sizeof(int) * n));

  for (i = 0 ; i < n ; i ++) {
    cin >> tmp; 
    list[i] = tmp;
  }

  mergeSort(list, 0, i);
  cout << list[k - 1] << endl;

  return 0;
}