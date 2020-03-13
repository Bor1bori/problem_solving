/**
 *
 * Title : JLIS
 * Date  : 2020-03-13
 * URL   : https://www.algospot.com/judge/problem/read/JLIS
 * Tags  : algospot, dynamicprogramming
 *
 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long NEGINF = numeric_limits<long long>::min();

int getMaxJILS(const vector<int>& sequenceA, const vector<int>& sequenceB, int idxA, int idxB, int cache[101][101]) {
  int& ret = cache[idxA + 1][idxB + 1];
  if (ret != 0) {
    return ret;
  }
  ret = 1;
  long long maxA = (idxA == -1) ? NEGINF : sequenceA[idxA];
  long long maxB = (idxB == -1) ? NEGINF : sequenceB[idxB];
  long long maxValueInJLIS = max(maxA, maxB);

  for (int i = idxA + 1 ; i != sequenceA.size() ; i++) {
    if (i != -1 && sequenceA[i] > maxValueInJLIS) {
      ret = max(ret, getMaxJILS(sequenceA, sequenceB, i, idxB, cache) + 1);
    }
  }
  for (int i = idxB + 1 ; i != sequenceB.size() ; i++) {
    if (i != -1 && sequenceB[i] > maxValueInJLIS) {
      ret = max(ret, getMaxJILS(sequenceA, sequenceB, idxA, i, cache) + 1);
    }
  }
  return ret;
}

void solve() {
  int sequenceNumberA, sequenceNumberB;
  vector<int> sequenceA, sequenceB;
  int cache[101][101] = {0, };

  cin >> sequenceNumberA >> sequenceNumberB;

  for (int i = 0 ; i < sequenceNumberA ; i++) {
    int tmp;
    cin >> tmp;

    sequenceA.push_back(tmp);
  }
  for (int i = 0 ; i < sequenceNumberB ; i++) {
    int tmp;
    cin >> tmp;

    sequenceB.push_back(tmp);
  }
  int result = getMaxJILS(sequenceA, sequenceB, -1, -1, cache);
  cout << result - 1 << endl;
}

int main() {
  int caseNumber;
  cin >> caseNumber;

  for (int i = 0; i < caseNumber; i++)
  {
    solve();
  }
  
}