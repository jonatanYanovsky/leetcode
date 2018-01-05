#include <iostream>
#include <string>

// Jonatan Yanovsky
// 1/5/2018
// solution for LeetCode - ZigZag Conversion

// algorithm:
// n = 3:
// i offset1 offset2
// 0	4		0
// 1	2		2
// 2	0		4

// n = 5:
// i offset1 offset2
// 0	8		0
// 1	6		2
// 2	4		4
// 3	2		6
// 4	0		8

// calculate offset1 = n*2 - 2*(i+1)
// calculate offset2 = 2*i

// Jump through chars in the string by alternating jump distance with offset{1 or 2} 
// this is for the purpose when we jump between chars with different distances.

// set output to true to see this in action:

bool output = true; // show inner workings

using namespace std;

class Solution {
public:
	string convert(string text, int nRows) {
		string out = "";
		int textSize = text.size();

		int base = nRows * 2;

		for (int i = 0; i < nRows; i++) {
			int idx = i;
			int offset1, offset2;

			offset1 = base - (2 * (i + 1));
			offset2 = i * 2;

			out.append(1, text.at(idx)); // first element at each row

			/*int bigger;
			if (offset1 >= offset2)
				bigger = offset1;
			else
				bigger = offset2;*/

			
			if (output) {
				/*if (i == 0)
					cout << text.at(idx) << string((offset1 / 2) - 1, ' ');*/
				if (i == nRows- 1)
					cout << text.at(idx) << string((offset2 / 2) - 1, ' ');
				else
					cout << text.at(idx) << string((offset1 / 2) - 1, ' ');
			}

			// subsequent elements at regular intervals of {offset1, offset2}
			while (1) {	// until we break (we reach the end of the string)			
				if (offset1 != 0) {
					idx += offset1;
					if (idx < textSize) { // within bounds
						out.append(1, text.at(idx));
						if (output) {
							if (offset2 != 0)
								cout << text.at(idx) << string((offset2 / 2) - 1, ' ');
							else 
								cout << text.at(idx) << string((offset1 / 2) - 1, ' ');
						}
					}
					else break;
				}

				if (offset2 != 0) {
					idx += offset2;
					if (idx < textSize) { // within bounds
						out.append(1, text.at(idx));
						if (output) {
							if (offset1 != 0)
								cout << text.at(idx) << string((offset1 / 2) - 1, ' ');
							else
								cout << text.at(idx) << string((offset2 / 2) - 1, ' ');
						}
					}
					else break;
				}
			}
			if (output)
				cout << endl;
		}

		return out;
	}
};


int main() {

	string myString;
	int rows;

	myString = "PAYPALISHIRING";
	rows = 3;

	Solution sol;

	cout << endl << myString << " : " << sol.convert(myString, rows) << endl << endl;

	myString = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; // use this to see full algorithm
	rows = 8;
	cout << endl << myString << " : " << sol.convert(myString, rows) << endl << endl;

	int x;
	cin >> x;

	return 0;
}