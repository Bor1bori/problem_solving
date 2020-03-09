/**
 *
 * Title : CLOCKSYNC
 * Date  : 2020-03-09
 * URL   : https://www.algospot.com/judge/problem/read/CLOCKSYNC
 * Tags  : algospot, 경우의수, 완전탐색
 *
 **/

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

/*
0, 1, 2
3, 7, 9, 11
4, 10, 14, 15
0, 4, 5, 6, 7
6, 7, 8, 10, 12
0, 2, 14, 15
3, 14, 15
4, 5, 7, 14, 15
1, 2, 3, 4, 5
3, 4, 5, 9, 13
*/
const int limit = 2000000000;

const bool switches[10][16] = {
  {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
  {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
  {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
};


void pullSwitches(array<int, 16> &clocks, int switchNumber) { 
  for (int i = 0 ; i < 16; i ++) {
    if (switches[switchNumber][i]) {
      if (clocks[i] == 3) {
        clocks[i] = 12;
      } else {
        clocks[i] -= 3;
      }
    }
  }
}

void pushSwitches(array<int, 16> &clocks, int switchNumber) { 
  for (int i = 0 ; i < 16; i ++) {
    if (switches[switchNumber][i]) {
      if (clocks[i] == 12) {
        clocks[i] = 3;
      } else {
        clocks[i] += 3;
      }
    }
  }
}

bool isSolved(const array<int, 16> &clocks) {
  for (int i = 0 ; i < 16; i ++) {
    if (clocks[i] != 12) {
      return false;
    }
  }
  return true;
}

int getMinimalCount(array<int, 16> &clocks, int switchNumber, int currentPushCount) {
  int pushCount = limit;

  if (isSolved(clocks)) {
    return currentPushCount;
  }

  if (switchNumber == 10) {
    return limit;
  }

  for (int i = 0 ; i < 4 ; i ++) {
    for (int j = 0 ; j < i ; j ++) {
      pushSwitches(clocks, switchNumber);
    }
    pushCount = min(getMinimalCount(clocks, switchNumber + 1, currentPushCount + i), pushCount);
    for (int j = 0 ; j < i ; j ++) {
      pullSwitches(clocks, switchNumber);
    }
  }

  return pushCount;
}

void solve() {
  array<int, 16> clocks;

  for (int i = 0 ; i < 16 ; i ++) {
    int inputTime;
    cin >> inputTime;

    clocks[i] = inputTime;
  }
  int result = getMinimalCount(clocks, 0, 0);
  cout << ( result == limit ? -1 : result) << endl;
}

int main() {
  int testCaseNumber;
  cin >> testCaseNumber; 

  for (int i = 0 ; i < testCaseNumber ; i ++) {
    solve();
  }
}