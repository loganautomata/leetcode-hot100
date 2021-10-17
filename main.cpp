#include <iostream>
#include <sstream>
#include "./lc300/solution.h"

using namespace std;

int main()
{
	Solution solution;

	vector<int> arr = {4, 10, 4, 3, 8, 9};

	cout << solution.lengthOfLIS(arr) << endl;

	return 0;
}
