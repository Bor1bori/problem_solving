/**
 *
 * Title : DFS와 BFS
 * Date  : 2020-04-23
 * URL   : https://www.acmicpc.net/problem/1260
 * Tags  : BFS, DFS
 *
 **/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void clearQueue(queue<int> &q) {
  queue<int> empty;
  swap(q, empty);
}

void dfs(vector<multiset<int>> &nodes, int idx, vector<bool> &visited) {
  if (visited[idx]) {
    return;
  }
  visited[idx] = true;
  cout << idx + 1 << " ";
  for (auto it = nodes[idx].begin() ; it != nodes[idx].end() ; it ++) {
    dfs(nodes, *it, visited);
  }
  return;
}

void bfs(vector<multiset<int>> &nodes, int startIdx, vector<bool> &visited) {
  queue<int> nextSearch({startIdx});
  while (!nextSearch.empty()) {
    queue<int> search(nextSearch);
    clearQueue(nextSearch);
    while (!search.empty()) {
      int idx = search.front();
      search.pop();
      if (visited[idx]) {
        continue;
      } else {
        visited[idx] = true;
        cout << idx + 1 << " ";
        for (auto innerIt = nodes[idx].begin() ; innerIt != nodes[idx].end() ; innerIt ++) {
          if (!visited[*innerIt]) {
            nextSearch.push(*innerIt);
          }
        }
      }
    }
  }
}

int main() {
  int n, m, v;
  vector<multiset<int>> nodes;
  vector<bool> visited;

  cin >> n >> m >> v;
  v --; // 번호를 index로 변경
  nodes.resize(n, multiset<int>());
  visited.resize(n, false);

  for (int i = 0 ; i < m ; i ++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;

    // 번호를 index로 변경, 0부터 셀거임
    tmp1 --;
    tmp2 --;
    nodes[tmp1].insert(tmp2);
    nodes[tmp2].insert(tmp1);
  }

  dfs(nodes, v, visited);
  cout << endl;

  visited.assign(n, false);  
  bfs(nodes, v, visited);
  cout << endl;
}