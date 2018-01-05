#include <iostream>
#include <math.h>
#include <vector>

// Jonatan Yanovsky
// 1/5/2018
// solution for LeetCode - Reverse Integer

using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool positive = (x >= 0); 
		if (!positive)
			x *= -1; // get rid of the negative sign

		vector<int> integers;

		int out = 0;

		while (x != 0) {
			integers.push_back(x % 10); // get the digits
			x /= 10;
		}

		int idx = 0;
		for (int i = integers.size() - 1; i >= 0; i--) { // reduce the digits
			out += integers[i] * pow(10, idx);
			idx++;
		}

		if (!positive)
			out *= -1; // make result negative if it is supposed to be

		return out;
	}
};

int main() {
	int a;
	Solution sol;

	a = 123;
	cout << endl << a << " : " << sol.reverse(a) << endl;
	a = -123;
	cout << endl << a << " : " << sol.reverse(a) << endl;
	a = 120;
	cout << endl << a << " : " << sol.reverse(a) << endl;

	int x;
	cin >> x;
	return 0;
}