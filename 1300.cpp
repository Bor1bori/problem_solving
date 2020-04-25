/**
 *
 * Title : K번째 수
 * Date  : 2020-04-25
 * URL   : https://www.acmicpc.net/problem/1300
 * Tags  : 이진탐색, binarysearch
 *
 **/
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

long long binarySearch(int start, int end) {
  int count = 0;
  int mid = (start + end) / 2;

  if (start >= end) {
    return start;
  }
  // mid가 몇번째 수인지
  for (int i = 1 ; i <= n ; i ++) {
    count += min(n, mid / i);
  }
  // mid보다 큰 값이다.
  if (count < k) {
    return binarySearch(mid + 1, end);
  }
  // mid보다 작거나 같은 값이다.
  if (count >= k) {
    return binarySearch(start, mid);
  }
}

int main() {
  cin >> n;
  cin >> k;
  cout << binarySearch(1, k) << endl;
}