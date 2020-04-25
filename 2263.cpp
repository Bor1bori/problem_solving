/**
 *
 * Title : 트리의 순회
 * Date  : 2020-04-25
 * URL   : https://www.acmicpc.net/problem/2263
 * Tags  : tree
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;

void printPreorder(int inStart, int inEnd, int postStart, int postEnd) {
  if (inStart > inEnd) {
    return;
  }
  int root = postorder[postEnd];
  int left = 0;

  if (inStart == inEnd) {
    printf("%d ", root);
    return;
  }

  while (inorder[inEnd - left] != root) {
    left ++;
  }
  printf("%d ", root);
  // 왼쪽
  printPreorder(inStart, inEnd - left - 1, postStart, postEnd - left - 1);
  // 오른쪽
  printPreorder(inEnd - left + 1, inEnd, postEnd - left, postEnd - 1);
}

int main() {
  int n;
  cin >> n;

  inorder.reserve(n);
  postorder.reserve(n);
  for (int i = 0 ; i < n ; i ++) {
    int tmp;
    cin >> tmp;
    inorder.push_back(tmp);
  }
  for (int i = 0 ; i < n ; i ++) {
    int tmp;
    cin >> tmp;
    postorder.push_back(tmp); 
  }
  printPreorder(0, n - 1, 0, n - 1);
}