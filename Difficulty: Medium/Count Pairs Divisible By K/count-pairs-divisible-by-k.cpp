class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto &num:arr){
            int r=num%k;
            cnt+=mp[(k-r)%k];
            mp[r]++;
        }
        return cnt;
    }
};

/*
2->2
1->1
3->1
1+1
*/