/**
 *
 * Title : DICTIONARY
 * Date  : 2020-04-17
 * URL   : https://www.algospot.com/judge/problem/read/DICTIONARY
 * Tags  : 
 *
 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const char base = 'a';
const int alphabetNum = 26;
vector<vector<int>> alphabetAdj(alphabetNum, vector<int>(alphabetNum, 0));
vector<int> seen(alphabetNum, 0);
vector<int> order;

void makeGraph() {
  int wordNumber;
  string prev, next;

  cin >> wordNumber;

  cin >> prev;
  for (int i = 1 ; i < wordNumber ; i ++) {
    cin >> next;
    char firstDiffAlphaPrev = 0;
    char firstDiffAlphaNext = 0;
    for (int j = 0 ; j < min(prev.size(), next.size()) ; j ++) {
      if (prev[j] != next[j]) {
        firstDiffAlphaPrev = prev[j];
        firstDiffAlphaNext = next[j];
        break;
      }
    }
    if (firstDiffAlphaPrev != 0) {
      alphabetAdj[firstDiffAlphaPrev - base][firstDiffAlphaNext - base] = 1;
    }
    prev.replace(prev.begin(), prev.end(), next);
  }
}


void dfs(int here) {
  seen[here] = 1;
  for (int there = 0 ; there < alphabetAdj.size() ; there ++) {
    if (alphabetAdj[here][there] && !seen[there]) {
      dfs(there);
    }
  }
  order.push_back(here);
}

vector<int> topologicalSort() {
  for (int i = 0 ; i < alphabetNum ; i ++) {
    if (!seen[i]) {
      dfs(i);
    }
  }
  reverse(order.begin(), order.end());

  for (int i = 0 ; i < alphabetNum ; i ++) {
    for (int j = i + 1 ; j < alphabetNum ; j ++) {
      if (alphabetAdj[order[j]][order[i]]) {
        return vector<int>();
      }
    }
  }
  return order;
}

void solve() {
  alphabetAdj.clear();
  alphabetAdj.resize(alphabetNum, vector<int>(alphabetNum, 0));
  seen.clear();
  seen.resize(alphabetNum, 0);
  order.clear();

  makeGraph();
  auto result = topologicalSort();
  if (result.size() == 0) {
    cout << "INVALID HYPOTHESIS" << endl;
    return;
  }
  for (auto it = result.begin() ; it != result.end() ; it ++) {
    cout << static_cast<char>('a' + *it);
  }
  cout << endl;
  return;  
}

int main() {
  int caseNumber;
  cin >> caseNumber;
  for (int i = 0 ; i < caseNumber ; i ++) {
    solve();
  }
}