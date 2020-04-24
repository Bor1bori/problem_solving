/**
 *
 * Title : 숨바꼭질
 * Date  : 2020-04-24
 * URL   : https://www.acmicpc.net/problem/1697
 * Tags  : BFS
 *
 **/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> visited;
int maxPosition;

void clearQueue(queue<int> &q) {
  queue<int> empty;
  swap(q, empty);
}

int getTimeViaBFS(int start, int end) {
  queue<int> nextSearch({start});
  int deepth = 0;

  while (!nextSearch.empty()) {
    queue<int> search(nextSearch);
    clearQueue(nextSearch);
    while (!search.empty()) {
      int position = search.front();
      if (position == end) {
        return deepth;
      }
      search.pop();
      visited[position] = 1;
      if (((position + 1) < maxPosition) && !visited[position + 1]) {
        nextSearch.push(position + 1);
      }
      if (((position - 1) >= 0) && !visited[position - 1]) {
        nextSearch.push(position - 1);
      }
      if (((position * 2) < maxPosition) && !visited[position * 2]) {
        nextSearch.push(position * 2);
      }
    }
    deepth ++;
  }
  return -1;
}

int main() {
  int startPosition, endPosition;
  cin >> startPosition >> endPosition;
  maxPosition = max(endPosition * 4 / 3 + 1, startPosition + 1); // 2x - endPosition = endposition - x 에서 x값이 2배가 되도 더 빠를 수 있는 x의 최대값
  visited.resize(maxPosition, 0);
  cout << getTimeViaBFS(startPosition, endPosition) << endl;
}