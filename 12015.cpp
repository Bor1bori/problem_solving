/**
 *
 * Title : 가장 긴 증가하는 수열2
 * Date  : 2020-04-26
 * URL   : https://www.acmicpc.net/problem/12015
 * Tags  : lis, binarysearch
 *
 **/

#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
  int n;
  vector<int> seq;
  set<int> partialSeq;

  cin >> n;
  seq.reserve(n);

  for (int i = 0 ; i < n ; i ++) {
    int tmp;
    cin >> tmp;

    seq.push_back(tmp);
  }
  partialSeq.insert(seq[0]);
  for (int i = 1 ; i < seq.size() ; i ++) {
    auto it = partialSeq.lower_bound(seq[i]);
    if (it == partialSeq.end()) {
      partialSeq.insert(seq[i]);
    } else {
      partialSeq.erase(it);
      partialSeq.insert(seq[i]);
    }
  }
  cout << partialSeq.size() << endl;
}