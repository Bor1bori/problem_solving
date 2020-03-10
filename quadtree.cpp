/**
 *
 * Title : QUADTREE
 * Date  : 2020-03-10
 * URL   : https://www.algospot.com/judge/problem/read/QUADTREE
 * Tags  : algospot, 분할정복
 *
 **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverse(string::iterator& it) {
  char head = *it;
  ++it;

  if (head == 'b' || head == 'w')
    return string(1, head);
  string upperLeft = reverse(it);
  string upperRight = reverse(it);
  string lowerLeft = reverse(it);
  string lowerRight = reverse(it);
  return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

void solve() {
  string compressedPainting;
  cin >> compressedPainting;
  if (compressedPainting.size() == 1) {
    cout << compressedPainting << endl;
    return;
  }
  auto it = compressedPainting.begin();
  string result = reverse(it);
  cout << result << endl;
}

int main() {
  int testCaseNumber;
  cin >> testCaseNumber;
  for (int i = 0 ; i < testCaseNumber ; i ++) {
    solve();
  }
}