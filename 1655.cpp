/**
 *
 * Title : 가운데를 말해요
 * Date  : 2020-04-23
 * URL   : https://www.acmicpc.net/problem/1655
 * Tags  : 우선순위힙
 *
 **/
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  int middle;
  priority_queue<int> maxPQ; // 중앙값보다 작은 값들
  priority_queue<int, vector<int>, greater<int>> minPQ; // 중앙값보다 큰 값들
  cin >> n;

  scanf("%d", &middle);
  printf("%d\n", middle);

  for (int i = 1 ; i < n ; i ++) {
    int tmp;
    scanf("%d", &tmp);
    if (tmp > middle) {
      minPQ.push(tmp);
    } else {
      maxPQ.push(tmp);
    }
    if (minPQ.size() >= (maxPQ.size() + 2)) { // middle보다 큰 값들이 많으면
      maxPQ.push(middle);
      middle = minPQ.top();
      minPQ.pop();
    } else if ((minPQ.size() + 1) <= maxPQ.size()) { // middle 보다 작은 값들이 많으면
      minPQ.push(middle);
      middle = maxPQ.top();
      maxPQ.pop();
    }
    printf("%d\n", middle);
  }
}