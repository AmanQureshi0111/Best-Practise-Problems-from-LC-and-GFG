class Solution {
	public:
	bool isPossible(vector<int>& arr, int s, int x) {
		// Generate the sequence written on the paper.
		vector<long long> seq;
		seq.push_back(s);
		
		long long prefSum = s;
		
		for (int val : arr) {
			long long cur = prefSum + val;
			seq.push_back(cur);
			prefSum += cur;
		}
		
		// Greedily subtract the largest possible values.
		long long target = x;
		
		for (int i = seq.size() - 1; i >= 0; i--) {
			if (seq[i] <= target)
				target -= seq[i];
		}
		
		return target == 0;
	}
};
