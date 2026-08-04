class Solution {
	public:
	int countPairs(vector<int>& arr, int k) {
		// code here
		int n = arr.size();
		
		// Sort the array in non-decreasing order
		sort(arr.begin(), arr.end());
		
		int res = 0;
		
		// Iterate through each index
		for (int i = 0; i < n; i++)
			{
			
			// val stores the threshold value; elements strictly less
			// than val will have a difference with arr[i] less than k.
			int val = arr[i] + k;
			
			// Find the index of the first element in the array which is
			// greater than or equal to val.
			int y = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
			
			// Add the count of all valid pairs possible for the current arr[i]
			res += (y - i - 1);
		}
		return res;
	}
};
/*
1 2 4 10
*/
