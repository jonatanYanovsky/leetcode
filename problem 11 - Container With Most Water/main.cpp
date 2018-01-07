#include <iostream>
#include <vector>

// Jonatan Yanovsky
// 1/6/2018
// solution for LeetCode - Container With Most Water

bool output = true;

using namespace std;

class Solution{
public:
	int MaxArea(vector<int>& height) { // two-pointer approach

		int vecSize = height.size();
		
		int left = 0;
		int right = vecSize - 1; // indices of elements being compared;

		int leftHeight = 0;
		int rightHeight = 0;

		int largestArea = 0;
		int area = 0;
		int minHeight = 0;
		bool leftMovedLast = true; // favor moving the pointer which has not moved

		while (left < right) {
			leftHeight = height[left];
			rightHeight = height[right]; // get height from vector

			minHeight = (leftHeight < rightHeight)? leftHeight : rightHeight; // get smaller (or equal) height
			area = minHeight * (right - left); // base height * distance between lines

			if (area > largestArea) {
				largestArea = area;

				if (output) {
					cout << "Elements: " << left << ", " << right << ". ";
					cout << "Heights: " << leftHeight << ", " << rightHeight << ". ";
					cout << "Distance between elements: " << right - left << ". ";
					cout << "Minimum Height: " << minHeight << ". ";
					cout << "Area: " << area << endl;
				}
			}
			
			// move the SMALLER height pointer closer to the LARGER
			if (leftHeight < rightHeight) {
				left++;
				leftMovedLast = true;
			}
			else if (leftHeight > rightHeight) {
				right--;
				leftMovedLast = false;
			}
			else if (leftMovedLast) { // equivalent height : move right
				right--;
				leftMovedLast = false;
			}
			else { // equivalent height : move left
				left++;
				leftMovedLast = true;
			}
		}

		return largestArea;
	}
};


int main() {

	Solution sol;
	vector<int> myHeight;

	myHeight = { 1, 2, 6, 8, 5, 4, 8, 3, 7 };
	cout << "In main: " << sol.MaxArea(myHeight) << endl << endl;

	myHeight = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	cout << "In main: " << sol.MaxArea(myHeight) << endl << endl;

	int x;
	cin >> x;
	return 0;
}