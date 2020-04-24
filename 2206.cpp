/**
 *
 * Title : 벽 부수고 이동하기
 * Date  : 2020-04-24
 * URL   : https://www.acmicpc.net/problem/2206
 * Tags  : BFS
 *
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000001;

// visited[a][b][c]라고 하면 (a, b, 0)은 (a, b)에서 벽을 안부수고 도달
// (a, b, 1)은 벽을 한 번 부수고 도달
int visited[1000][1000][2];
int mapInfo[1000][1000];
const vector<pair<int, int>> movePairs{make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

void clearQueue(queue<vector<int>> &q) {
  queue<vector<int>> empty;
  swap(q, empty);
}

int bfs(pair<int, int> startPosition, const pair<int, int>& goalPosition) {
  queue<vector<int>> nextSearch;
  nextSearch.push(vector<int>{startPosition.first, startPosition.second, 0});
  int deepth = 1;
  visited[0][0][0] = 1;

  while (!nextSearch.empty()) {
    queue<vector<int>> search(nextSearch);
    clearQueue(nextSearch);
    while (!search.empty()) {
      vector<int> node = search.front();
      if (node[0] == goalPosition.first && node[1] == goalPosition.second) {
        return deepth;
      }
      search.pop();
      for (auto it = movePairs.begin() ; it != movePairs.end() ; it ++) {
        if ((node[0] + (*it).first) < 0 || (node[0] + (*it).first) > goalPosition.first
        || (node[1] + (*it).second) < 0 || (node[1] + (*it).second) > goalPosition.second) { // 경계를 넘어갈 경우
          continue;
        }
        if (!mapInfo[node[0] + (*it).first][node[1] + (*it).second]) { // 가려는 방향에 벽이 없을 경우
          if (!visited[node[0] + (*it).first][node[1] + (*it).second][node[2]]) { // 그리고 아직 방문 X일 경우
            visited[node[0] + (*it).first][node[1] + (*it).second][node[2]] = 1;
            nextSearch.push(vector<int>{node[0] + (*it).first, node[1] + (*it).second, node[2]});
          }
        } else {
          if (node[2] == 0 && !visited[node[0] + (*it).first][node[1] + (*it).second][1]) { // 아직 벽을 뚫지 않고 방문 X일 경우
            visited[node[0] + (*it).first][node[1] + (*it).second][1] = 1;
            nextSearch.push(vector<int>{node[0] + (*it).first, node[1] + (*it).second, 1});
          }
        }
      }
    }
    deepth ++;
  }
  return -1;
}

int main() {
  int n, m;
  memset(visited, 0, sizeof(int) * 1000 * 1000 * 2);
  cin >> n >> m;
  cin.ignore();
  
  for (int i = 0 ; i < n ; i ++) {
    for (int j = 0 ; j < m ; j ++) {
      mapInfo[i][j] = (cin.get() - '0');
    }
    cin.ignore();
  }
  cout << bfs(make_pair(0, 0), make_pair(n - 1, m - 1)) << endl;
}