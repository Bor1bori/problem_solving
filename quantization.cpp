/**
 *
 * Title : QUANTIZE
 * Date  : 2020-04-13
 * URL   : https://www.algospot.com/judge/problem/read/QUANTIZE
 * Tags  : algospot, dynamicprogramming
 *
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int maxInt = numeric_limits<int>::max() / 2 - 1;
int memoiSumSquaredErr[100][100][10];

int getSumSquaredErr(vector<int> &sequence, int currentIdx, int numberOf, int remainApproxiNum) {
  int &ret = memoiSumSquaredErr[currentIdx][numberOf][remainApproxiNum];

  if (ret != -1) {
    return ret;
  }
  ret = maxInt;
  if (numberOf < remainApproxiNum) {
    ret = getSumSquaredErr(sequence, currentIdx, numberOf, remainApproxiNum - 1);
    return ret;
  }

  if (remainApproxiNum == 1) {
    double sum = 0;
    for (int i = currentIdx ; i < currentIdx + numberOf ; i ++) {
      sum += sequence[i];
    }
    int approxi = round(sum / numberOf);
    int sumSquaredErr = 0;
    for (int i = currentIdx ; i < currentIdx + numberOf ; i ++) {
      sumSquaredErr += (sequence[i] - approxi) * (sequence[i] - approxi);
    }
    ret = sumSquaredErr;
    return ret;
  }
  int remainIdx = sequence.size() - currentIdx;
  for (int i = 1 ; i < remainIdx ; i ++) {
    ret = min(ret, getSumSquaredErr(sequence, currentIdx, i, 1) + getSumSquaredErr(sequence, currentIdx + i, remainIdx - i, remainApproxiNum - 1));
  }

  return ret;
}

void solve() {
  int seqNum, approxiNum;
  vector<int> sequence;

  memset(memoiSumSquaredErr, -1, sizeof(int) * 100 * 100 * 10);

  cin >> seqNum >> approxiNum;

  for (int i = 0 ; i < seqNum ; i ++) {
    int tmp;
    cin >> tmp;
    sequence.push_back(tmp);
  }

  sort(sequence.begin(), sequence.end());
  cout << getSumSquaredErr(sequence, 0, sequence.size(), approxiNum) << endl;

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