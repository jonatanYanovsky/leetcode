#include <iostream>
#include <vector>

// Jonatan Yanovsky
// 1/4/2018
// solution for LeetCode - Median of Two Sorted Arrays

// log(m + n) algorithm explanation: 
// similar to how you would compute a median on paper:
// cross off the values of each array until you are left with either two middle values (return average)
// or you are left with one value in the middle (in this algorithm represented by 3 elements remaining).

// To do that, continuously reduce problem size by 2: (only when problem size is not 2 or 3): 
// Pick a middle value for each array. Then compute the average of the two middle values.
// from there, cross off lower values in the top vector, and higher values in the bottom vector.
// Pick a new range for the top and bottom by:
// Travel right along top vector from the last middle point until you find a value that is greater 
// than the previous median.
// Travel left along bottom vector from the last middle point until you find a value that is less 
// than the previous median.
// Jump back up to the top

// 3-value case:
// case 1: pick the middle element of the three (pick only 3 total elements in both vectors)
// case 2: pick the average of top or bottom two (pick if not case 1)

bool displayBounds = false; // display algorithm inner workings?

using namespace std;

class Solution {
public:
	double MedianOfTwoSortedArrays(vector<int>& a, vector<int>& b) {
		
		if (displayBounds) {
			for (int i = 0; i < a.size(); i++) { // print top 
				cout << a[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < b.size(); i++) { // print bottom 
				cout << b[i] << " ";
			}
			cout << endl << endl;
		}

		double ret;

		// a = top, b = bottom
		int top, bottom;

		// pick initial middle elements:

		if (a.size() % 2 == 0) // even
			top = (a.size() - 1) / 2; // start at just before the middle element
		else // odd
			top = a.size() / 2; // start at middle element

		if (b.size() % 2 == 0) // even
			bottom = (b.size() + 1) / 2; // start at just after the middle element
		else // odd
			bottom = b.size() / 2; // start at middle element

		double median = 0;

		int topRange = a.size() - 1; // from top to topRange
		int bottomRange = 0; // from bottomRange to bottom

		int totalSize = (topRange - top + 1) + (bottom - bottomRange + 1); // for the while loop check
		
		while (totalSize > 3) { // total elements > 3

			int aVal = a[top];
			int bVal = b[bottom]; // choices for median computation
			
			if (aVal == bVal) { // same value case. Can return from here
				cout << "The median is (" << aVal << " + " << bVal << ")/2 = " << aVal;
				return aVal; 
			}

			median = (double) (aVal + bVal) / 2; // median for comparison
			
			topRange = top; // top bounds = {top to topRange}
			bottomRange = bottom; // bottom bounds = {bottomRange to bottom}

			while ((topRange + 1) < a.size() && a[topRange + 1] < median) { // top: shift right-bound left
				topRange++;
			}
			while ((bottomRange - 1) >= 0 && median < b[bottomRange - 1]) { // bottom: shift left-bound right
				bottomRange--;
			}

			top = ceil((double)(topRange + top) / 2); // top: shift left-bound right
			bottom = (bottom + bottomRange) / 2; // bottom: shift right-bound left

			if (displayBounds) {
				for (int i = top; i <= topRange; i++) { // print top bounds
					cout << a[i] << " ";
				}
				cout << endl;
				for (int i = bottomRange; i <= bottom; i++) { // print bottom bounds
					cout << b[i] << " ";
				}
				cout << endl << endl;
			}

			totalSize = (topRange - top + 1) + (bottom - bottomRange + 1); // while loop check
		}
		if (totalSize == 3) {
			if (displayBounds) {
				for (int i = top; i <= topRange; i++) { // print top bounds
					cout << a[i] << " ";
				}
				cout << endl;
				for (int i = bottomRange; i <= bottom; i++) { // print bottom bounds
					cout << b[i] << " ";
				}
				cout << endl << endl;
			}

			int absoluteSize = a.size() + b.size();

			// case 1: pick the middle element of the three 
			// pick if only 3 total elements in both vectors
			if (absoluteSize == 3) {
				int v1, v2, v3;
				
				if (a.size() == 2) {
					v1 = a[0];
					v2 = a[1]; // top 2
					v3 = b[0];
				}
				else {
					v1 = a[0];
					v2 = b[0]; // bottom 2
					v3 = b[1];
				}

				if (v1 <= v2 && v2 <= v3) {
					cout << "The median is " << (double) v2 << endl;
					return v2;
				}
				if (v2 <= v1 && v1 <= v3) // pick middle
				{
					cout << "The median is " << (double)v1 << endl;
					return v1;
				}
				if (v1 <= v3 && v3 <= v2)
				{
					cout << "The median is " << (double)v3 << endl;
					return v3;
				}
			}
			// case 2: pick the average of top or bottom two
			// pick if not case 1
			else {
				int topSize = topRange - top + 1;
				if (topSize == 2) { // top has 2
					int aVal = a[top];
					int bVal = a[topRange];

					ret = (double)(aVal + bVal) / 2;
					cout << "The median is (" << aVal << " + " << bVal << ")/2 = " << ret << endl;
					return ret;
				}
				else { // bottom has 2
					int aVal = b[bottom];
					int bVal = b[bottomRange];

					ret = (double)(aVal + bVal) / 2;
					cout << "The median is (" << aVal << " + " << bVal << ")/2 = " << ret << endl;
					return ret;
				}
			}
		}
		if (totalSize == 2) { // only one element remaining on top and bottom
			int aVal = a[top];
			int bVal = b[bottom];

			ret = (double)(aVal + bVal) / 2;
			cout << "The median is (" << aVal << " + " << bVal << ")/2 = " << ret << endl;
			return ret;
		}
	}
};


int main() {

	vector<int> a, b;
	Solution sol;

	a = { 1, 3 };
	b = { 2 };

	sol.MedianOfTwoSortedArrays(a, b);
	cout << endl;

	a = { 1, 2 };
	b = { 3, 4 };

	sol.MedianOfTwoSortedArrays(a, b);
	cout << endl;

	a = { 1, 2, 3, 4, 5, 6 };
	b = { 2, 2, 7, 8, 9, 9};

	sol.MedianOfTwoSortedArrays(a, b);
	cout << endl;

	int x;
	cin >> x;
	return 0;
}