/**
 *
 * Title : 내리막 길
 * Date  : 2020-04-24
 * URL   : https://www.acmicpc.net/problem/1520
 * Tags  : DynamicPrograming
 *
 **/

#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> mapInput;
vector<vector<int>> memoi;
vector<pair<int, int>> directions{make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

int countPath(int y, int x) {
  if (y < 0 || y >= mapInput.size() || x < 0 || x >= mapInput[0].size()) {
    return 0;
  }
  // y, x가 m-1, n-1일 경우 memoi[m-1][n-1]에 이미 1이 들어있어서 리턴됨
  int &ret = memoi[y][x];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  for (auto it = directions.begin() ; it != directions.end() ; it ++) {
    int newY = y + (*it).first;
    int newX = x + (*it).second;
    if (newY < 0 || newY >= mapInput.size() || newX < 0 || newX >= mapInput[0].size()) {
      continue;
    }
    // 내리막이 아닐때 가지 않음
    if (mapInput[y][x] <= mapInput[newY][newX]) {
      continue;
    }
    ret += countPath(y + (*it).first, x + (*it).second);
  }
  return ret;
}

int main() {
  int n, m;

  cin >> m >> n;

  mapInput.resize(m, vector<int>(n, 0));
  memoi.resize(m, vector<int>(n, -1));
  memoi[m-1][n-1] = 1;

  for (int i = 0 ; i < m ; i ++) {
    for (int j = 0 ; j < n ; j ++) {
      int tmp;
      cin >> tmp;
      mapInput[i][j] = tmp;
    }
  }
  cout << countPath(0, 0) << endl;
}