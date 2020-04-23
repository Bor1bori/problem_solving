/**
 *
 * Title : 그대로 출력하기
 * Date  : 2020-04-23
 * URL   : https://www.acmicpc.net/problem/11718
 * Tags  : 입출력
 *
 **/

#include <iostream>
#include <string>

using namespace std;

void solve1() {
  string tmp;
  while (!cin.eof()) {
    getline(cin, tmp);
    cout << tmp << endl;
  }
}

void solve2(){
  char buf[101];
  while (!cin.eof()) {
    cin.getline(buf, 100, '\n');
    cout << buf << endl;
  }
}

void solve3(){
  char buf[101];
  cin >> buf;
  cout << buf << endl;
  cin.ignore();
  while (!cin.eof()) {
    cin.getline(buf, 101, '\n');
    cout << buf << endl;
  }
}

int main() {
  solve3();
}