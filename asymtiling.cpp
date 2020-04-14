/**
 *
 * Title : ASYMTILING
 * Date  : 2020-04-13
 * URL   : https://www.algospot.com/judge/problem/read/ASYMTILING
 * Tags  : algospot, dynamicprogramming
 *
 **/

#include <iostream>
#include <cstring>

using namespace std;

int MOD = 1000000007;
int memoi[101];

int getTiling(int n) {
  if (n <= 1) return 1;
  int &ret = memoi[n];
  if (ret != -1) return ret;


  ret = (getTiling(n - 1) + getTiling(n - 2)) % MOD;
  return ret;
}

void solve() {
  int width;
  int result, sym;
  memset(memoi, -1, sizeof(int) * 101);
  cin >> width;
  if (width == 1) {
    cout << 0 << endl;
    return;
  }
  if (width == 2) {
    cout << 0 << endl;
    return;
  }
  if (width == 3) {
    cout << 2 << endl;
    return;
  }
  result = getTiling(width);
  if (width % 2 == 1) {
    result = (result + MOD - getTiling(width / 2)) % MOD;
  } else {
    result = (result + MOD - getTiling(width / 2)) % MOD;
    result = (result + MOD - getTiling(width / 2 - 1)) % MOD;
  }

  cout << result << endl;
}

int main() {
  int caseNum;
  cin >> caseNum;

  for (int i = 0 ; i < caseNum ; i ++) {
    solve();
  }
}