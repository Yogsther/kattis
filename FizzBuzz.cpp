#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {

	int x;
	int y;
	int n;
	cin >> x >> y >> n;

	for (int i = 1; i <= n; i++) {
		string print = "";
		if (i % x == 0) print += "Fizz";
		if (i % y == 0) print += "Buzz";
		if (print != "") cout << print << endl;
		else cout << i << endl;
	}
}