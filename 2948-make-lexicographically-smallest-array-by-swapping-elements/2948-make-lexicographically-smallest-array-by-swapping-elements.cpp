class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> arr(nums);
        sort(arr.begin(),arr.end());
        
        int grp_no=0;
        unordered_map<int,int> groupNum;
        groupNum[arr[0]]=grp_no;

        unordered_map<int,list<int>> groupList;
        groupList[grp_no].push_back(arr[0]);

        for(int i=1;i<n;i++){
            if(abs(arr[i-1]-arr[i])>limit) grp_no++;
            groupNum[arr[i]]=grp_no;
            groupList[grp_no].push_back(arr[i]);
        }

        for(int i=0;i<n;i++){
            int group=groupNum[nums[i]];
            int num= *(groupList[group].begin());
            nums[i]=num;
            groupList[group].pop_front();
        }

        return nums;
    }
};