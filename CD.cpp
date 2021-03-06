/*

Sample data

8 7
1
10
60
70
240
250
34536
1000000000
1
10
60
34536
345734
24572458
1000000000
0 0

#Correct answer 5


*/

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	long long n, m;
	cin >> n >> m;

	vector<long long> nVector;
	vector<long long> mVector;

	for (int i = 0; i < n + m; i++) {
		long long push;
		cin >> push;
		if (i < n) nVector.push_back(push);
		else mVector.push_back(push);
	}

	long long cdToSell = 0;

	vector<long long> loopVector = mVector;
	vector<long long> checkVector = nVector;
	if (nVector.size() > mVector.size()) {
		loopVector = nVector;
		checkVector = mVector;
	}

	for (int i = 0; i < loopVector.size(); i++) {
		vector<long long>::iterator itr = find(checkVector.begin(), checkVector.end(), loopVector.at(i));
		if (itr != checkVector.cend()) {
			cdToSell++;
		}
	}

	cout << cdToSell << endl;
}
