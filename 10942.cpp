/**
 *
 * Title : 팰린드롬?
 * Date  : 2020-04-24
 * URL   : https://www.acmicpc.net/problem/10942
 * Tags  : DynamicProgramming
 *
 **/

#include <iostream>
#include <vector>
using namespace std;

void updatePalindrome(vector<int> &numbers, vector<int> &palindromeLength) {
  for (int i = 0 ; i < numbers.size() * 2 ; i ++) {
    int left, right;
    if ((i % 2) == 0) { // ex) 0번부터 4번까지
      left = i / 2;
      right = i / 2;
    } else { // ex) 0번부터 3번까지
      left = i / 2;
      right = i / 2 + 1;
    }
    for (int j = 0 ; ; j ++) {
      if ((left - j) < 0 || right + j >= numbers.size() || (numbers[left - j] != numbers[right + j])) {
        palindromeLength[i] = j * 2 + (i % 2);
        break;
      }
    }
  }
}

int main() {
  int n, m;
  vector<int> numbers;
  vector<int> palindromeLength;

  cin >> n;
  numbers.reserve(n);
  palindromeLength.resize(2 * n, 0);
  for (int i = 0 ; i < n ; i ++) {
    int tmp;
    cin >> tmp;
    numbers.push_back(tmp);
  }
  updatePalindrome(numbers, palindromeLength);

  cin >> m;
  for (int i = 0 ; i < m ; i ++) {
    int s, e;
    scanf("%d %d", &s, &e);
    if (palindromeLength[s - 1 + e - 1] > (e - s)) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
}