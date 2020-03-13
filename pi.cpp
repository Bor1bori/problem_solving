/**
 *
 * Title : PI
 * Date  : 2020-03-13
 * URL   : https://www.algospot.com/judge/problem/read/PI
 * Tags  : algospot, dynamicprogramming
 *
 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long NEGINF = numeric_limits<long long>::min();

int getMinimumDifficultyInFragment(string& numberFragment) {
  bool flagA = true, flagB = true, flagC = true, flagD = true;
  int difference = numberFragment[1] - numberFragment[0];
  if (difference != 0) {
    flagA = false;
  }
  if (abs(difference) != 1) {
    flagB = false;
  }
  int newDifference;

  for (auto it = numberFragment.begin() + 2 ; it != numberFragment.end() ; it ++) {
    newDifference = *it - *(it - 1);
    if (newDifference != 0) {
      flagA = false;
    }
    if (newDifference != difference) {
      flagB = false;
      flagD = false;
    }
    if (*it != *(it - 2)) {
      flagC = false;
    }
  }
  if (flagA) {
    return 1;
  } else if (flagB) {
    return 2;
  } else if (flagC) { 
    return 4;
  } else if (flagD) {
    return 5;
  } else {
    return 10;
  }
}

int getDifficultyFromIdx(string& numberToMemory, int idx, int cache[10000]) {
  if (idx == numberToMemory.size()) {
    return 0;
  }
  if (idx > numberToMemory.size() - 2) {
    return 10 * 10000;
  }
  int& ret = cache[idx];
  if (ret != 0) {
    return ret;
  }
  ret = 10 * 10000;


  string substrLen3(numberToMemory, idx, 3), substrLen4(numberToMemory, idx, 4), substrLen5(numberToMemory, idx, 5);
  ret = min(ret, getMinimumDifficultyInFragment(substrLen3) + getDifficultyFromIdx(numberToMemory, idx + 3, cache));
  ret = min(ret, getMinimumDifficultyInFragment(substrLen4) + getDifficultyFromIdx(numberToMemory, idx + 4, cache));
  ret = min(ret, getMinimumDifficultyInFragment(substrLen5) + getDifficultyFromIdx(numberToMemory, idx + 5, cache));

  return ret;
}

void solve() {
  int cache[10000] = {0, };
  string numberToMemory;
  cin >> numberToMemory;

  cout << getDifficultyFromIdx(numberToMemory, 0, cache) << endl;
  return;
}

int main() {
  int caseNumber;
  cin >> caseNumber;

  for (int i = 0; i < caseNumber; i++)
  {
    solve();
  }
  
}