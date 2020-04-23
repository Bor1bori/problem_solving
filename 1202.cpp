/**
 *
 * Title : 보석 도둑
 * Date  : 2020-04-23
 * URL   : https://www.acmicpc.net/problem/1202
 * Tags  : 
 *
 **/
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
  int n, k;
  priority_queue<pair<int, int>> pq; // pair(가격, 무게) 내림차순으로 정렬
  multiset<int> backpacks; // 백팩의 무게 값들, 오름차순
  unsigned long long result = 0;

  cin >> n >> k;

  for (int i = 0 ; i < n ; i ++) {
    int weight, value;
    cin >> weight >> value;
    pq.push(make_pair(value, weight));
  }
  for (int i = 0 ; i < k ; i ++) {
    int maxWeight;
    cin >> maxWeight;
    backpacks.insert(maxWeight);
  }
  
  for ( ; backpacks.size() != 0 && pq.size() != 0; pq.pop()) {
    pair<int, int> jewelry = pq.top();
    auto it = backpacks.lower_bound(jewelry.second);

    if (it != backpacks.end()) {
      backpacks.erase(it);
      result += jewelry.first;
    }
  }
  cout << result << endl;

  return 0;
}