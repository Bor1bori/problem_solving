/**
 *
 * Title : WILDCARD
 * Date  : 2020-03-13
 * URL   : https://www.algospot.com/judge/problem/read/WILDCARD
 * Tags  : algospot, dynamicprogramming
 *
 **/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string normalizeWildcard(string::iterator& wildcardIter) {
}

bool match(string& wildcard, string& fileName, int wildcardIdx, int fileNameIdx, int cache[101][101]) {
  if (cache[wildcardIdx][fileNameIdx]) {
    return false;
  }
  cache[wildcardIdx][fileNameIdx] = 1;

  if (wildcardIdx == wildcard.size() && fileNameIdx == fileName.size()) {
    return true;
  }

  if (wildcardIdx == wildcard.size()) {
    return false;
  }

  if (wildcard[wildcardIdx] == fileName[fileNameIdx] || wildcard[wildcardIdx] == '?') {
    return match(wildcard, fileName, wildcardIdx + 1, fileNameIdx + 1, cache);
  }

  if (wildcard[wildcardIdx] == '*') {
    if (fileNameIdx != fileName.size()) {
      return match(wildcard, fileName, wildcardIdx, fileNameIdx + 1, cache) || match(wildcard, fileName, wildcardIdx + 1, fileNameIdx, cache);
    } else {
      return match(wildcard, fileName, wildcardIdx + 1, fileNameIdx, cache);
    }
  }

  return false;
}

void solve() {
  string wildcard;
  int fileNameNumber;
  vector<string> matchedString;

  cin >> wildcard;
  cin >> fileNameNumber;

  for (int i = 0 ; i < fileNameNumber ; i ++) {
    string fileName;
    int cache[101][101] = {0, };
    cin >> fileName;
    if (match(wildcard, fileName, 0, 0, cache)) {
      matchedString.push_back(fileName);
    }
  }
  sort(matchedString.begin(), matchedString.end());
  for (auto it = matchedString.begin() ; it != matchedString.end() ; it ++) {
    cout << *it << endl;
  }
}

int main() {
  int caseNumber;
  cin >> caseNumber;

  for (int i = 0 ; i < caseNumber ; i ++) {
    solve();
  }
  
}