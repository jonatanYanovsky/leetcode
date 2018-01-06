#include <iostream>
#include <string>
#include <math.h>
#include <vector>

// Jonatan Yanovsky
// 1/5/2018
// solution for LeetCode - String to Integer (atoi)

// skip whitespace, then start at an integer and keep going until you reach a non-integer value;
// return 0 if you start with a letter or special character (abc.ABC;$%&%^$)
// return 0 if you do not hit any integers before you hit a character (after a minus sign)
// return INTMAX/INTMIN if out of range
// otherwise return the integer

using namespace std;

class Solution{
public:
	int myAtoi(string str) {

		int out = 0;
		vector<int> digits;
		bool hasSeenIntegerValue = false;
		bool isPositive = true;
		int idx = 0;

		for (int i = 0; i < str.size(); i++) {
			
			int val = (int)str[i];

			if (val == 45) { // starts with dash (minus sign)
				isPositive = false; 

				idx = i + 1; // now find the rest of the integer or if no integer return with 0
				val = (int)str[idx]; // char to ASCII
				while (47 < val && val < 58) {
					hasSeenIntegerValue = true;

					val = str[idx] - '0'; // convert char to int (0-9)
					digits.push_back(val);// add the new value to our vector

					idx++;
					val = (int)str[idx];
				}

				if (!hasSeenIntegerValue) // if has only seen a dash '-'
					return 0;
				else
					break; // we have already seen the end of the integer in the string
			}
			else if (47 < val && val < 58) { // starts with integer
				hasSeenIntegerValue = true;

				val = str[i] - '0'; // convert char to int (0-9)
				digits.push_back(val); // add the first value to our vector

				idx = i + 1;

				val = (int)str[idx]; // char to ASCII
				while (47 < val && val < 58) {

					val = str[idx] - '0'; // convert char to int (0-9)
					digits.push_back(val);// add the new value to our vector

					idx++;
					val = (int)str[idx];
				}

				break; // we have already seen the end of the integer in the string
			}
			else if (val != 32) // non-whitespace such as a letter
				return 0; // return on first non-{digit, dash, whitespace} value
		}
		
		if (hasSeenIntegerValue) {
			if (out > INT32_MAX)
				return INT32_MAX;

			if (out < INT32_MIN)
				return INT32_MIN;

			for (int i = digits.size() - 1; i >= 0; i--) {
				out += digits[i] * pow(10, digits.size() - i - 1); // compute out
			}

			if (!isPositive)
				out *= -1;

			return out;
		}
		else 
			return 0;
	}
};


int main() {

	string s;
	Solution sol;

	s = "123 s 345"; // 123
	cout << s << endl << sol.myAtoi(s) << endl << endl;

	s = " s 345"; // 0
	cout << s << endl << sol.myAtoi(s) << endl << endl;

	s = "  345"; // 345
	cout << s << endl << sol.myAtoi(s) << endl << endl;

	s = "  111111111111111111111122222222222233333333333334444444444444345"; // INTMAX/INTMIN
	cout << s << endl << sol.myAtoi(s) << endl << endl;

	int x;
	cin >> x;
	return 0;
}