/**
 *
 * Title : 퇴사
 * Date  : 2020-04-18
 * URL   : https://www.acmicpc.net/problem/14501
 * Tags  : 
 *
 **/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 15;
int memoi[MAXN]; // n + 1일에 일을 했을 때 n + 1일부터 N일까지 벌 수 있는 돈의 최고

int getPay(vector<pair<int, int>> &schedule, int dayN) {
  if (dayN >= schedule.size()) {
    return 0;
  }
  int spend = schedule[dayN].first;
  if (dayN + spend > schedule.size()) {
    return getPay(schedule, dayN + 1);
  }
  int &ret = memoi[dayN];
  if (ret != -1) {
    return ret;
  }
  int pay = schedule[dayN].second;

  ret = max(getPay(schedule, dayN + 1), pay + getPay(schedule, dayN + spend));

  return ret;
}

int main() {
  int workingDaysNum;
  vector<pair<int, int>> schedule; // 소요일, 임금

  cin >> workingDaysNum;
  memset(memoi, -1, sizeof(int) * MAXN);

  for (int i = 0 ; i < workingDaysNum ; i ++) {
    int daySpend, pay;
    cin >> daySpend >> pay;
    schedule.push_back(make_pair(daySpend, pay));
  }

  cout << getPay(schedule, 0);
}