#include <iostream>
#include <string>

// Jonatan Yanovsky
// 1/7/2018
// solution for LeetCode - Roman to Integer

using namespace std;

class Solution {
public:
	int RomanToInt(string s) {
		int stringSize = s.size();
		int val;
		int lastVal;
		int total = 0;
		bool justChecked = false;
		
		char last;
		char current; // digits

		current = s[0]; // first digit in string
		if (stringSize == 1)
			return getDigitValue(current);

		int index = 0; // start from second digit
		while (index < stringSize) {
			if (justChecked == false) { // only get the digit if we haven't already done
				current = s[index]; //     so in the last iteration
				val = getDigitValue(current);
			}
			if (index + 1 >= stringSize) { // this is the last element
				total += val;
				return total;
			}
			// this is NOT the last element, aka there is another element after this one:
			
			last = current;
			lastVal = val; // move from old element

			current = s[index + 1];
			val = getDigitValue(current); // get next element

			if (lastVal >= val) { // move to the next value
				index++;
				total += lastVal;
				justChecked = true;
			}
			else { // next value is larger than this one, do a subtraction
				total += val - lastVal;
				index += 2;
				justChecked = false;
			}
		}
		return total;
	}

private:
	int getDigitValue(char digit) {
		if (digit == 'I')
			return 1;
		if (digit == 'V')
			return 5;
		if (digit == 'X')
			return 10;
		if (digit == 'L')
			return 50;
		if (digit ==  'C')
			return 100;
		if (digit == 'D')
			return 500;
		if (digit == 'M')
			return 1000;
		return -10000000; // garbage to let us know we messed up
	}
};

int main() {

	Solution sol;
	string myString;

	myString = "MMMCMXCIX";
	cout << myString << " : " << sol.RomanToInt(myString) << endl;

	myString = "MCMXCIII";
	cout << myString << " : " << sol.RomanToInt(myString) << endl;

	int x;
	cin >> x;
	return 0;
}