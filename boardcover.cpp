/**
 *
 * Title : BOARDCOVER
 * Date  : 2020-03-09
 * URL   : https://www.algospot.com/judge/problem/read/BOARDCOVER
 * Tags  : algospot, 경우의수, 완전탐색
 *
 **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct CellLocation
{
  int y;
  int x;
};

enum CoveredOrNot
{
  COVERED,
  NOT_COVERED
};

// dy dx
const int coverDeltaByType[4][3][2] = {
  { {0, 0}, {1, 0}, {0, 1} },
  { {0, 0}, {0, 1}, {1, 1} },
  { {0, 0}, {1, 0}, {1, 1} },
  { {0, 0}, {1, 0}, {1, -1} }
};

bool canCover(const vector<vector<CoveredOrNot>>& board, CellLocation currentCellLocation, int type) {
  int y = currentCellLocation.y;
  int x = currentCellLocation.x;

  for (int i = 0; i < 3 ; i ++) {
    int ny = y + coverDeltaByType[type][i][0];
    int nx = x + coverDeltaByType[type][i][1];

    if (ny >= board.size() || ny < 0 || nx < 0 || nx >= board[i].size() || board[ny][nx] == COVERED) {
      return false;
    }
  }
  return true;
}

void coverOrDiscover(CoveredOrNot coverOrNot, vector<vector<CoveredOrNot>>& board, CellLocation currentCellLocation, int type) {
  int y = currentCellLocation.y;
  int x = currentCellLocation.x;

  for (int i = 0; i < 3 ; i ++) {
    int ny = y + coverDeltaByType[type][i][0];
    int nx = x + coverDeltaByType[type][i][1];

    board[ny][nx] = coverOrNot;
  }

  return;
}

int countCoverWay(vector<vector<CoveredOrNot>>& board) {
  struct CellLocation firstNotCoveredCell = {
    -1, -1
  };
  int count = 0;

  for (int y = 0 ; y < board.size() ; y ++) {
    for (int x = 0 ; x < board[0].size() ; x ++) {
      if (board[y][x] == NOT_COVERED) {
        firstNotCoveredCell = {
          y, x
        };
        break;
      }
    }
    if (firstNotCoveredCell.y != -1) {
      break;
    }
  }

  if (firstNotCoveredCell.y == -1) {
    return 1;
  }
  
  for (int coverType = 0 ; coverType < 4 ; coverType ++) {
    if (canCover(board, firstNotCoveredCell, coverType)) {
      coverOrDiscover(COVERED, board, firstNotCoveredCell, coverType);
      count += countCoverWay(board);
      coverOrDiscover(NOT_COVERED, board, firstNotCoveredCell, coverType);
    }
  }
  return count;
}

void solve() {
  int width, height;
  
  cin >> height;
  cin >> width;
  cin.ignore(100, '\n');

  vector<vector<CoveredOrNot>> board;

  for (int y = 0 ; y < height ; y ++) {
    vector<CoveredOrNot> row;
    for (int x = 0 ; x < width ; x ++) {
      CoveredOrNot isCovered = cin.get() == '#' ? COVERED : NOT_COVERED;
      row.push_back(isCovered);
    }
    board.push_back(row);
    cin.ignore(100, '\n');
  }

  cout << countCoverWay(board) << endl;
}

int main() {
  int testCaseNumber;
  cin >> testCaseNumber;

  for (int i = 0 ; i < testCaseNumber ; i ++) {
    solve();
  }

}