/**
 *
 * Title : BRACKETS2
 * Date  : 2020-04-17
 * URL   : https://www.algospot.com/judge/problem/read/BRACKETS2
 * Tags  : 
 *
 **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  string input;
  vector<char> stack;

  cin >> input;

  for (auto it = input.begin(); it != input.end() ; it ++) {
    if (*it == '(' || *it == '{' || *it == '[') {
      stack.push_back(*it);
    } else {
      if (*it == ')' && stack.size() > 0 && stack.back() == '(') {
        stack.pop_back();
      } else if (*it == '}' && stack.size() > 0 && stack.back() == '{') {
        stack.pop_back();
      } else if (*it == ']' && stack.size() > 0 && stack.back() == '[') {
        stack.pop_back();
      } else {
        cout << "NO" << endl;
        return;
      }
    }
  }
  if (stack.size() == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return;
}

int main() {
  int caseNumber;
  cin >> caseNumber;

  for (int i = 0 ; i < caseNumber ; i ++) {
    solve();
  }
}