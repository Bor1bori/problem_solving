/**
 *
 * Title : 수 이어 쓰기 2
 * Date  : 2020-04-18
 * URL   : https://www.acmicpc.net/problem/1790
 * Tags  : 
 *
 **/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int getNumberOfDigits(int num) {
  int ret = 1;
  for (num ; num >= 10 ; num /= 10) {
    ret += 1;
  }
  return ret;
}

int main() {
  int n, k, ret;
  int len = 0;

  cin >> n >> k;

  for (int i = 1 ; i <= n ; i ++) {
    int addLen = getNumberOfDigits(i);
    len += addLen;
    if (len >= k) {
      int toGetNumber = len - k + 1;
      int mod = pow(10, toGetNumber);
      ret = i % mod;
      ret = ret / pow(10, toGetNumber - 1);
      cout << ret << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}