#include <iostream>
#include <string>
#include <vector>
#include <set>

// Jonatan Yanovsky
// Solution for leetcode - Longest Substring Without Repeating Characters
// 1/3/2018

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		set<char> mySet; // characters we have already seen

		vector<string> mySubstrings; // holds our strings
		mySubstrings.push_back(""); 

		int substringNum = 0; // which substring are we looking at

		for (char& c : s) {
			if (mySet.find(c) != mySet.end()) { // found a copy of a character
				substringNum++; // move to next substring
				mySet.clear(); // empty the characters that we have seen
				mySubstrings.push_back(""); // create a new substring
			}

			mySet.insert(c); // seen character
			mySubstrings[substringNum].append(1, c); // add to substring
		}

		int largest = 0; // largest string

		for (int i = substringNum; i >= 0; i--) { // find length of largest substring in the vector
			int ln = mySubstrings[i].length();

			if (ln > largest)
				largest = ln; // assign next largest length
		}

		return largest;
	}
};


int main() {
	string a, b, c;
	a = "abcabcbb"; // abc = 3
	// abc abc b b
	b = "bbbbb"; // b = 1
	// b b b b b
	c = "pwwkew"; // wke = 3
	// pw wke w

	Solution sol;
	cout << sol.lengthOfLongestSubstring(a) << endl;
	cout << sol.lengthOfLongestSubstring(b) << endl;
	cout << sol.lengthOfLongestSubstring(c) << endl;

	int x;
	cin >> x;
	return 0;
}
