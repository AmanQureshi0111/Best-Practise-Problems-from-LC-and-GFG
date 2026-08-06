class Solution {
	public:
	int countMinOperations(vector<int>& arr) {
		// code here
		vector<int> nums = arr;
		int ops = 0;
		
		while (true) {
			bool allZero = true;
			for (int val : nums) {
				if (val != 0) {
					allZero = false;
					break;
				}
			}
			
			if (allZero) {
				return ops;
			}
			
			// Undo increment operations for any odd numbers
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] & 1) {
					nums[i]--;
					ops++;
				}
			}
			
			bool hasNonZero = false;
			for (int val : nums) {
				if (val > 0) {
					hasNonZero = true;
					break;
				}
			}
			
			// Undo one simultaneous doubling operation
			// by dividing all elements by 2
			if (hasNonZero) {
				for (int& val : nums) {
					val /= 2;
				}
				ops++;
			}
		}
		return ops;
	}
};
/*
1 1 1

2 2
*/
