#include <iostream>

// Jonatan Yanovsky
// 1/6/2018
// solution for LeetCode - Palindrome Number

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int middle, left, right; // indices for our digits
		numDigits = 0;

		if (x < 0)
			return false; // negative number -> not a palindrome

		int temp = x;

		while (temp > 0) { // get total digits in x
			temp /= 10;
			numDigits++;
		}

		if (numDigits % 2 == 0) { // even
			middle = (numDigits - 1) / 2;
		}
		else { // odd
			middle = numDigits / 2; // rounds down
		}

		int low, high; // digit values 

		if (numDigits % 2 == 0) { // even setup

			left = middle;
			right = middle + 1; // indices of digits
		}
		else { // odd setup
			left = middle - 1;
			right = middle + 1; // indices of digits
		}

		while (left >= 0 && right < numDigits) { // check all digits
			low = getDigit(x, left);
			high = getDigit(x, right); // get the digits

			if (low != high) // if not equal, x is not a palindrome
				return false;

			left--; // next two digits
			right++;
		}
		return true; // we've gone through all the digits
	}

private:
	int numDigits;

	int getDigit(const int val, const int idx) { // a function to get the value of a digits at an index
		int temp = val;
		for (int i = 0; i < (numDigits - 1) - idx; i++) // get digit + lower index digits
			temp /= 10;

		return (temp % 10); // get digit
	}
};

int main() {

	int myInt[6] = { -123, 123, 121, 4544, 4554, 123454321 };
	Solution sol;

	for (int val : myInt) {
		cout << val << " is ";

		if (sol.isPalindrome(val))
			cout << "a palindrome." << endl;
		else
			cout << "not a palindrome." << endl;
	}

	int z;
	cin >> z;
	return 0;
}