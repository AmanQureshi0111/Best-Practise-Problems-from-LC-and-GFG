class Solution {
public:
    //
    bool isCovers(vector<int> &a,vector<int> &b){
        return a[0]<=b[0] && a[1]>=b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>=b[1];
            }
            return a[0]<b[0];
        });
        int i=0;
        int cnt=0;
        int n=intervals.size();
        while(i<n){
            int j=i+1;
            while(j<n && isCovers(intervals[i],intervals[j])) j++;
            i=j;
            cnt++;
        }
        return cnt;
    }
};
/*
[[2,8],[3,6]]
*/