/**
 *
 * Title : PICNIC
 * Date  : 2020-03-04
 * URL   : https://www.algospot.com/judge/problem/read/PICNIC
 * Tags  : algospot, 경우의수, 탐색
 *
 **/

#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;



int countPair(const set<int> unpairedStudents, bool areFriend[10][10]) {
	if (unpairedStudents.empty()) {
		return 1;
	}
	int count = 0;
	int selectorStudent;
	for (auto iter = unpairedStudents.begin(); iter != unpairedStudents.end(); iter++) {
		if (iter == unpairedStudents.begin()) {
			selectorStudent = *iter;
			continue;
		}
		if (areFriend[selectorStudent][*iter]) {
				set<int> newUnpairedStudents(unpairedStudents);
			newUnpairedStudents.erase(newUnpairedStudents.find(selectorStudent));
			newUnpairedStudents.erase(newUnpairedStudents.find(*iter));
			count += countPair(newUnpairedStudents, areFriend);
		}
	}
	return count;
}

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	int testCaseNum;
	cin >> testCaseNum;
	for (int i = 0; i < testCaseNum; i++) {
		bool areFriend[10][10] = { false };
		int studentsNumber, friendPairNumber;
		string temp;
		string friendPairInput;
		set<int> students;


		cin >> temp;
		studentsNumber = stoi(temp);
		cin >> temp;
		friendPairNumber = stoi(temp);

		for (int i = 0; i < studentsNumber; i++) {
			students.insert(i);
		}

;		for (int j = 0; j < friendPairNumber; j++) {
			cin >> temp;
			int firstStudent = stoi(temp);
			cin >> temp;
			int secondStudent = stoi(temp);
			areFriend[firstStudent][secondStudent] = true;
			areFriend[secondStudent][firstStudent] = true;
		}
		
		int pairCount = countPair(students, areFriend);
		cout << pairCount << endl;

	}
}

