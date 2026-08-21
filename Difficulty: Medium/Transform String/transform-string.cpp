class Solution {
	public:
	int transform(string &s1, string &s2) {
		int n = s1.length();
		if (n != s2.length())
			return - 1;
		unordered_map<char,int> mp;
		for(int i=0;i<n;i++){
		    mp[s1[i]]++;
		    mp[s2[i]]--;
		}
		for(auto &it:mp){
		    if(it.second != 0) return -1;
		}
		int j = n - 1;
		int res = 0;
		int i=n-1;
		while (i>=0) {
			if (s1[i] != s2[j]) {
				res++;
			} else {
				j--;
			}
			i--;
		}
		
		return res;
	}
};
