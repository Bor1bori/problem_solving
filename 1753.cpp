/**
 *
 * Title : 최단경로
 * Date  : 2020-04-24
 * URL   : https://www.acmicpc.net/problem/1753
 * Tags  : Dijkstra
 *
 **/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int MAX = 40000000;
vector<vector<pair<int, int>>> nodes; // 간선의 vector ; pair.first 도착 노드, pair.second 가중치

vector<int> dist;

void calcDijkstra(int startNode) {
  // pair<해당 노드까지 길이, 노드>
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, startNode));

  while (!pq.empty()) {
    pair<int, int> popped = pq.top();
    pq.pop();
    if (dist[popped.second] <= popped.first) {
      continue;
    }
    dist[popped.second] = popped.first;
    for (auto it = nodes[popped.second].begin() ; it != nodes[popped.second].end() ; it ++) {
      // 기존에 있던 경로보다 작으면
      if (popped.first + (*it).second < dist[(*it).first]) {
        pq.push(make_pair(popped.first + (*it).second, (*it).first));
      }
    }
  }
}

int main() {
  int nodesNum, linesNum, startNode;
  cin >> nodesNum >> linesNum;
  cin >> startNode;
  nodes.resize(nodesNum, vector<pair<int, int>>{});
  dist.resize(nodesNum, MAX);
  for (int i = 0 ; i < linesNum ; i ++) {
    int u, v, w;
    cin >> u >> v >> w;
    nodes[u - 1].push_back(make_pair(v - 1, w));
  }
  calcDijkstra(startNode - 1);
  
  for (auto it = dist.begin() ; it != dist.end() ; it ++) {
    if ((*it) == MAX) {
      cout << "INF\n";
    } else {
      cout << *it << "\n";
    }
  }
  return 0;
}