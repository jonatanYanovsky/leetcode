#include <iostream>
#include <map>
#include <vector>

// Jonatan Yanovsky
// solution for leetcode - Two Sum   
// 1/1/2018

using namespace std;

class Solution {
public:
	vector<int> TwoSumBruteForce(vector<int>& arr, int target) {
		for (int i = 0; i < arr.size(); i++) {
			int complement = target - arr[i];

			for (int j = i + 1; j < arr.size(); j++) {
				if (arr[j] == complement)
					return { i, j };
			}
		}
		return { -1 };
	}

	vector<int> TwoSumTwoPass(vector<int>& arr, int target) {
		map<int, int> myMap;

		for (int i = 0; i < arr.size(); i++) 
			myMap.insert({arr[i], i});

		for (int i = 0; i < arr.size(); i++) {
			int complement = target - arr[i];
			auto it = myMap.find(complement);

			if (it != myMap.end() && i != it->second) 
				return { i, it->second };
		}
		return { -1 };
	}

	vector<int> TwoSumSinglePass(vector<int>& arr, int target) {
		map<int, int> myMap;

		for (int i = 0; i < arr.size(); i++) {
			int complement = target - arr[i];

			// check if complement is in myMap
			auto it = myMap.find(complement);
			if (it != myMap.end() && it->first != arr[i]) {
				return {it->second, i};
			}

			myMap.insert({arr[i], i}); // add arr[i] to myMap
		}
		return { -1 };
	}
};

int main() {

	vector<int> myArr{ 1, 2, 5, 9, 7, 11, 15 }; // out: 2, 6
	int myTarget = 20;
	vector<int> mySolution;

	Solution sol;

	mySolution = sol.TwoSumBruteForce(myArr, myTarget);
	if (mySolution[0] != -1)
		cout << mySolution[0] << " " << mySolution[1] << endl;
	else
		cout << "bug1";

	mySolution = sol.TwoSumTwoPass(myArr, myTarget);
	if (mySolution[0] != -1)
		cout << mySolution[0] << " " << mySolution[1] << endl;
	else
		cout << "bug2";

	mySolution = sol.TwoSumSinglePass(myArr, myTarget);
	if (mySolution[0] != -1)
		cout << mySolution[0] << " " << mySolution[1] << endl;
	else
		cout << "bug3";

	char x;
	cin >> x;

	return 0;
}