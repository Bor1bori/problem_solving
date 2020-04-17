/**
 *
 * Title : ITES
 * Date  : 2020-04-17
 * URL   : https://www.algospot.com/judge/problem/read/ITES
 * Tags  : 
 *
 **/

#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 50000000;
const long long a0 = 1983;


long long getNextAIdx(long long aIdx) {
  return (aIdx * 214013 + 2531011) % (static_cast<long long>(1) << 32);
}
int getNextInput(long long aIdx) {
  int ret = (aIdx % 10000) + 1;    
  return ret;
}

void solve() {
  int n, k;
  queue<int> range;
  int sum = 0 ;
  int ret = 0;
  long long aIdx = a0;

  cin >> k >> n;
  for (int i = 0 ; i < n ; i ++) {
    int input = getNextInput(aIdx);
    aIdx = getNextAIdx(aIdx);
    range.push(input);
    sum += input;
    while (sum > k) {
      sum -= range.front();
      range.pop();

    }
    if (sum == k) {
      ret += 1;
    } 
  }
  cout << ret << endl;
}

int main() {
  int caseNumber;
  cin >> caseNumber;
  for (int i = 0 ; i < caseNumber ; i ++) {
    solve();
  }
}