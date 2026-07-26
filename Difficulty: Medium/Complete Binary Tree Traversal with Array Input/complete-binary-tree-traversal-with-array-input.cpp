class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> ans;
        int i=0;
        int nodes=1;
        int n=arr.size();
        while(i<n){
            int temp=nodes;
            vector<int> nums;
            while(temp && i<n){
                nums.push_back(arr[i++]);
                temp--;
            }
            nodes*=2;
            sort(nums.begin(),nums.end());
            ans.push_back(nums);
        }
        return ans;
    }
};
