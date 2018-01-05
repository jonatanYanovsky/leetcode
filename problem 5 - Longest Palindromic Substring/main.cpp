#include <iostream>
#include <vector>
#include <string>

// Jonatan Yanovsky
// 1/4/2018
// solution for LeetCode - Longest Palindromic Substring

using namespace std;

class Solution {
public:
	string LongestPalindrome(string s) { // assume string has at least two characters
		
		vector<string> substrings;
		string currentSubstr = "";

		// first check for 2-element palindrome such as "aa"
		for (int i = 0; i < s.size() - 1; i++) {
			currentSubstr = "";
			bool newSubstr = false;

			int low = i; // this element
			int high = i + 1; // the element just to the right

			// check if within bounds and get next two elements on either side
			while ((low >= 0 && high < s.size()) && (s.at(low) == s.at(high))) {
				currentSubstr.insert(0, 1, s.at(low)); // insert before
				currentSubstr += s.at(high); // insert after
				
				low--;
				high++; // move to next two elements on the edges

				newSubstr = true; // non-empty substring, so add to vector
			}

			if (newSubstr) 
				substrings.push_back(currentSubstr); // add currentSubstr to the vector
		}

		// do the same as above but for 3-element palindromes such as "aba"
		for (int i = 0; i < s.size() - 1; i++) { // insert before
			currentSubstr = s.at(i); // insert after
			bool newSubstr = false;
			
			int low = i - 1; // left element
			int high = i + 1; // right element
			while ((low >= 0 && high < s.size()) && (s.at(low) == s.at(high))) {
				currentSubstr.insert(0, 1, s.at(low));
				currentSubstr += s.at(high); // add the next two chars

				low--;
				high++; // move to next two elements on the edges

				newSubstr = true; // non-empty substring, so add to vector
			}
		
			if (newSubstr)
				substrings.push_back(currentSubstr); // add currentSubstr to the vector
		}
		
		// return longest substring in the vector
		int largest = 0;
		int largestIdx = -1;

		for (int i = 0; i < substrings.size(); i++) { // find index of largest
			if (substrings[i].size() > largest) {
				largest = substrings[i].size();
				largestIdx = i;
			}
		}

		if (largestIdx == -1)
			return "-1";
		else
			return substrings[largestIdx];
	}
};

int main() {

	string myString;
	Solution sol;

	myString = "babad";
	cout << myString << " : " << sol.LongestPalindrome(myString) << endl;
	myString = "cbbd";
	cout << myString << " : " << sol.LongestPalindrome(myString) << endl;
	myString = "cbbdaaa";
	cout << myString << " : " << sol.LongestPalindrome(myString) << endl;
	myString = "badab";
	cout << myString << " : " << sol.LongestPalindrome(myString) << endl;

	int x;
	cin >> x;

	return 0;
}