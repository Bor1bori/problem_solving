/**
 *
 * Title : POLY
 * Date  : 2020-04-15
 * URL   : https://www.algospot.com/judge/problem/read/POLY
 * Tags  : algospot, DP
 *
 **/


#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10000000;

// memoi[a][b]는 쌓인 squares중 가장 위에 쌓인게 a이고 남은 사각형 수가 b일때 값
int memoi[101][101];

int countMonoPolyomino(int recentSquares, int remainSquares) {
  int &ret = memoi[recentSquares][remainSquares];

  if (ret != -1) {
    return ret;
  }

  if (remainSquares == 0) {
    ret = 1;
    return ret;
  }

  ret = 0;
    for (int i = 1 ; i <= remainSquares ; i ++) {
      ret += (recentSquares + i - 1) * countMonoPolyomino(i, remainSquares - i);
      ret = ret % MOD;
  }
  return ret;
}

void solve() {
  int squareNumber, result = 0;
  cin >> squareNumber;

  memset(memoi, -1, sizeof(int) * 101 * 101);

  for (int i = 1 ; i <= squareNumber ; i ++) {
    result += countMonoPolyomino(i, squareNumber - i);
    result = result % MOD;
  }
  cout << result << endl;
}

int main() {
  int caseNumber;
  cin >> caseNumber;

  for (int i = 0 ; i < caseNumber ; i ++) {
    solve();
  }
}