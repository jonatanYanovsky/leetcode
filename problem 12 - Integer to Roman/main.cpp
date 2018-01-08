#include <iostream>
#include <string>
#include <math.h>

// Jonatan Yanovsky
// 1/7/2018
// solution for LeetCode - Integer to Roman

using namespace std;

class Solution {
public:
	string IntToRoman(int num) {
		if (num > 3999)
			return "Greater than max representable Roman number";
		if (num < 1)
			return "Less than minimum range";

		string out = "";
		int leadingDigit = 0;
		int powerOfTen = 1000;

		for (int i = 3; i >= 0; i--) { // starting from leftmost digit move towards rightmost digit
			
			leadingDigit = num / powerOfTen; // get leading digit
			if (leadingDigit != 0) {

				low = letters[i][0];
				medium = letters[i][1];
				high = letters[i][2];

				out.append(formula(leadingDigit));
				num -= leadingDigit * powerOfTen; // get rid of leading digit so we can get the next one
			}
			powerOfTen /= 10; // move to next digit (towards the right)
		}
		return out;
	}

private:
	string letters[4] = {"IVX", "XLC", "CDM", "M  "}; // IVX, XLC, CDM, M__ = {low, medium, high}
	string low, medium, high;

	//  formula    =  _ __ ___ _- - -_ -__ -___ _^ = where _ is low, - is medium, ^ is high
	//	letters[0] =  I II III IV V VI VII VIII IX = example for the last digit 
	string formula(int digit) {
		string ret = "";

		switch (digit) {
			case 1: ret.append(low);
				break;
			case 2: ret.append(low + low);
				break;
			case 3: ret.append(low + low + low);
				break;
			case 4: ret.append(low + medium);
				break;
			case 5: ret.append(medium);
				break;
			case 6: ret.append(medium + low);
				break;
			case 7: ret.append(medium + low + low);
				break;
			case 8: ret.append(medium + low + low + low);
				break;
			case 9: ret.append(low + high);
				break;
			default: ret += "!!!";
		}
		return ret;
	}
};

int main() {

	Solution sol;
	int myInt;

	myInt = 3999;
	cout << myInt << " : " << sol.IntToRoman(myInt) << endl;

	myInt = 430;
	cout << myInt << " : " << sol.IntToRoman(myInt) << endl;

	int x;
	cin >> x;
	return 0;
}