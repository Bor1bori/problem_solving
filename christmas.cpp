/**
 *
 * Title : CHRISTMAS
 * Date  : 2020-04-16
 * URL   : https://www.algospot.com/judge/problem/read/CHRISTMAS
 * Tags  : 
 *
 **/
#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 20091101;
const int MAX = 100001;
vector<int> partialSums;
map<int, set<int>> classifiedPartialSums; // 
int memoi[MAX];

int christmas1() {
  long long ret = 0;
  for (auto it = classifiedPartialSums.begin() ; it != classifiedPartialSums.end() ; it ++) {
    // nC2 계산
    long long num = (*it).second.size();
    ret += num * (num - 1) / 2;

    ret %= MOD ;
  }
  return static_cast<int>(ret);
}

int christmas2(int currentIdx) { // currentIdx부터 나머지까지의 결과값 ex) currentIdx가 2 ; 2번부터 4번까지 = psum(4) - psum(1);
  if (currentIdx >= partialSums.size()) {
    return 0;
  }
  int &ret = memoi[currentIdx];
  if (ret != -1) {
    return ret;
  }
  int key = partialSums[currentIdx - 1];
  auto it = classifiedPartialSums.find(key);
  auto nextIdxIt = (*it).second.upper_bound(currentIdx - 1);
  if (nextIdxIt != (*it).second.end()) { // currentIdx에 해당하는 상자부터 *nextIdxIt까지 상자를 선택할 수 있을 경우
    ret = max(christmas2(currentIdx + 1), 1 + christmas2(*nextIdxIt + 1));
  } else { // 열 수 없을 경우 다음 idx부터의 값과 같음
    ret = christmas2(currentIdx + 1);
  }
  return ret;
}

void solve() {
  int boxNumber, childrenNumber;
  int sum = 0 ;
  int tmp;

  memset(memoi, -1, sizeof(int) * (MAX));
  partialSums.clear();
  classifiedPartialSums.clear();

  cin >> boxNumber >> childrenNumber;

  partialSums.push_back(0);
  classifiedPartialSums.insert(make_pair(0, set<int>({0})));
  for (int i = 0 ; i < boxNumber ; i ++) {
    cin >> tmp;
    sum = (sum + tmp) % childrenNumber;
    partialSums.push_back(sum);
    auto it = classifiedPartialSums.find(sum);
    if (it == classifiedPartialSums.end()) {
      set<int> newSet;
      newSet.insert(i + 1);
      classifiedPartialSums.insert(make_pair(sum, newSet));
    } else {
      (*it).second.insert(i + 1);
    }
  }

  cout << christmas1() << " " << christmas2(1) << endl;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int caseNumber;
  cin >> caseNumber;

  for (int i = 0 ; i < caseNumber ; i ++) {
    solve();
  }
}