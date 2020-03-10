/**
 *
 * Title : FENCE
 * Date  : 2020-03-10
 * URL   : https://www.algospot.com/judge/problem/read/FENCE
 * Tags  : algospot, 분할정복
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxAreaWithinIter(vector<int>& fence, vector<int>::iterator topestIter, vector<int>::iterator begin, vector<int>::iterator end) {
  int width = 1;
  int lowHeight = *topestIter;

  int area = lowHeight * width;

  int newArea = 0;

  auto leftestIter = topestIter;
  auto rightestIter = topestIter;

  do
  {
    int leftHeight = 0;
    int rightHeight = 0;

    if (leftestIter != begin) {
      leftHeight = *(leftestIter - 1);
    }

    if (rightestIter != (end - 1)) {
      rightHeight = *(rightestIter + 1);
    }

    if (leftHeight > rightHeight) {
      leftestIter -= 1;
      width += 1;
      lowHeight = min(leftHeight, lowHeight);
      newArea = width * lowHeight;
    } else {
      rightestIter += 1;
      width += 1;
      lowHeight = min(rightHeight, lowHeight);
      newArea = width * lowHeight;
    }
    area = max(area, newArea);
    if (newArea == 0) {
      break;
    }
  } while (true);
  return area;
}

vector<int>::iterator getTopestIter(vector<int>& fence, vector<int>::iterator begin, vector<int>::iterator end) {
  vector<int>::iterator topestIter = begin;
  for (auto it = begin ; it != end ; it ++) {
    if (*topestIter < *it) {
      topestIter = it;
    }
  }
  return topestIter;
}

int findMaxArea(vector<int>& fence, vector<int>::iterator begin, vector<int>::iterator end) {
  if (begin == end) {
    return 0;
  }
  int area = 0;
  auto topestIter = getTopestIter(fence, begin, end);

  area = max(area, findMaxArea(fence, begin, topestIter));
  area = max(area, findMaxArea(fence, topestIter + 1, end));
  area = max(area, getMaxAreaWithinIter(fence, topestIter, begin, end));

  return area;
}

void solve() {
  int fenceNumber;
  cin >> fenceNumber;
  vector<int> fence;

  for (int i = 0 ; i < fenceNumber ; i ++) {
    int height;
    cin >> height;
    fence.push_back(height);
  }
  int result = findMaxArea(fence, fence.begin(), fence.end());
  cout << result << endl;
  return;
}

int main() {
  int c;
  cin >> c;

  for (int i = 0 ; i < c ; i ++) {
    solve();
  }
}