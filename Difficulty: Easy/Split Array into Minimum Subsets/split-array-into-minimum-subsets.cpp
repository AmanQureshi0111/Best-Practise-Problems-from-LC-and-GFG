class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int &num:arr) mp[num]++;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]>0){
                cnt++;
            }
            int num=arr[i];
            while(mp[num]>0){
                mp[num]--;
                num++;
            }
        }
        return cnt;
    }
};
