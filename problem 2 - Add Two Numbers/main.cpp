#include <iostream>
#include <forward_list>
#include <math.h>

// Jonatan Yanovsky
// solution for leetcode - Add Two Numbers
// 1/2/2018

using namespace std;

class Solution {
public:
	// assume two lists of same length
	forward_list<int> AddTwoNumbers(forward_list<int>& a, forward_list<int>& b) {

		forward_list<int> out;
		forward_list<int>::iterator itA, itB, itOut;
		itA = a.begin();
		itB = b.begin();
		itOut = out.before_begin();

		int aVal = 0;
		int bVal = 0;

		do {
			aVal = *itA;
			bVal = *itB;
			itOut = out.insert_after(itOut, aVal + bVal);
			itA++;
			itB++;
		} 
		while (itA != a.end());

		return out;
	}

	forward_list<int> ConvertIntToList(int n) {
		forward_list<int> out;
		forward_list<int>::iterator it = out.before_begin();

		do {
			int div = n % 10;
			it = out.insert_after(it, div); // digits in reverse order
			n /= 10;
		} 
		while (n != 0);

		return out;
	}

	int ConvertListToInt(forward_list<int>& myList) {
		int out = 0;
		int i = 0;

		for (int& val : myList) {
			out += val * (int) pow(10, i);
			i++;
		}
		return out;
	}
};


int main() {

	int a = 342;
	int b = 465;

	Solution sol;

	forward_list<int> aList = sol.ConvertIntToList(a);
	forward_list<int> bList = sol.ConvertIntToList(b);

	forward_list<int> yList = sol.AddTwoNumbers(aList, bList);
	int y = sol.ConvertListToInt(yList);

	cout << a << " + " << b << " = " << y;

	int x;
	cin >> x; // terminate
	
	return 0;
}