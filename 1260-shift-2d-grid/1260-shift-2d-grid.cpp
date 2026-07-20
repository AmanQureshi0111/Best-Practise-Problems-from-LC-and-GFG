class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int len=n*m;
        vector<int> arr(len);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[(n*i+j+k)%len]=grid[i][j];
            }
        }
        k=k%len;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=n*i+j;
                ans[i][j]=arr[idx];
            }
        }
        return ans;
    }
};