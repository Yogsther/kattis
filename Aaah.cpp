#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Get input
	string jon, doctor;
	cin >> jon >> doctor;
	// Evaluate input and print output.
	if (jon.length() > doctor.length() || jon.length() == doctor.length()) cout << "go" << endl;
	else cout << "no" << endl;

	return 0;
}

// https://open.kattis.com/submissions/3007769