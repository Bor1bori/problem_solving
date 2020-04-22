/**
 *
 * Title : DSLR
 * Date  : 2020-04-22
 * URL   : https://www.acmicpc.net/problem/9019
 * Tags  : BFS
 *
 **/

#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

int computeR(int before) {
  int after = (before / 10) + (before % 10) * 1000;
  return after;
}

int computeL(int before) {
  int after = ((before * 10) % 10000) + (before / 1000);
  return after;
}

void dslr() {
  int init, final;
  queue<pair<string, int>> q;
  int visitedNumbers[10000] = {0, };
  string result;

  cin >> init >> final; // init != final

  q.push(make_pair(string(), init));
  visitedNumbers[init] = 1;
  while(1) {
    pair<string, int> nodeToVisit = q.front();
    q.pop();
    pair<string, int> nodeD = make_pair(nodeToVisit.first + "D", (nodeToVisit.second * 2) % 10000);
    pair<string, int> nodeS = make_pair(nodeToVisit.first + "S", (nodeToVisit.second + 9999) % 10000);
    pair<string, int> nodeL = make_pair(nodeToVisit.first + "L", computeL(nodeToVisit.second));
    pair<string, int> nodeR = make_pair(nodeToVisit.first + "R", computeR(nodeToVisit.second));

    // 만약 찾았으면 result에 값 넣고 break
    if (nodeD.second == final) {
      result = nodeD.first;
      break;
    } else if (nodeS.second == final) {
      result = nodeS.first;
      break;
    } else if (nodeL.second == final) {
      result = nodeL.first;
      break;
    } else if (nodeR.second == final) {
      result = nodeR.first;
      break;
    }

    // 방문할 큐에 추가
    if (visitedNumbers[nodeD.second] == 0) {
      visitedNumbers[nodeD.second] = 1;
      q.push(nodeD);
    }
    if (visitedNumbers[nodeS.second] == 0) {
      visitedNumbers[nodeS.second] = 1;
      q.push(nodeS);
    }
    if (visitedNumbers[nodeL.second] == 0) {
      visitedNumbers[nodeL.second] = 1;
      q.push(nodeL);
    }
    if (visitedNumbers[nodeR.second] == 0) {
      visitedNumbers[nodeR.second] = 1;
      q.push(nodeR);
    }
  }

  cout << result << endl;
}

int main() {
  int testCaseNum;
  cin >> testCaseNum;

  for (int i = 0 ; i < testCaseNum ; i ++) {
    dslr();
  }
}