class Solution {
	public:
	int maxSumWithK(vector<int>& arr, int k) {
		// code here
		// Calculate initial sum of
		// first k elements (first window)
		int sum = 0;
		for (int i = 0; i < k; i++)
			{
			sum += arr[i];
		}
		
		int last = 0;
		int j = 0;
		int maxSum = INT_MIN;
		maxSum = max(maxSum, sum);
		
		// Process rest of the array after first k elements
		for (int i = k; i < arr.size(); i++)
			{
			// Add current element to window sum
			sum = sum + arr[i];
			
			// Add element at j to the accumulated prefix
			last = last + arr[j++];
			
			// Update maxSum if current window sum is greater
			maxSum = max(maxSum, sum);
			
			// Remove the accumulated negative prefix
			// if it increases the overall subarray sum
			if (last < 0)
				{
				sum = sum - last;
				maxSum = max(maxSum, sum);
				last = 0;
			}
		}
		
		return maxSum;
	}
};
