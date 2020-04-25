/**
 *
 * Title : 점프 점프
 * Date  : 2020-04-25
 * URL   : https://www.acmicpc.net/problem/11060
 * Tags  : dynamicprogramming
 *
 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maze;
vector<int> memoi;
const int MAX = 100000;

int leastJump(int idx) {
  if (idx == (maze.size() - 1)) {
    return 0;
  }
  if (idx >= maze.size()) {
    return 100000;
  }
  int &ret = memoi[idx];
  if (ret != -1) {
    return ret;
  }
  ret = MAX;

  for (int i = 1 ; i <= maze[idx] ; i ++) {
    ret = min(ret, 1 + leastJump(idx + i));
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  maze.reserve(n);
  memoi.resize(n, -1);

  for (int i = 0 ; i < n ; i ++) {
    int tmp;
    cin >> tmp;
    maze.push_back(tmp);
  }
  int ret = leastJump(0);
  if (ret >= MAX) {
    cout << -1 << endl;
  } else {
    cout << ret << endl;
  }
}