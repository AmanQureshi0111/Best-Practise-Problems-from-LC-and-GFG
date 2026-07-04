class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans={{1}};
        for(int i=0;i<numRows-1;i++){
            vector<int> row={1};
            for(int j=1;j<ans[i].size();j++){
                row.push_back(ans[i][j]+ans[i][j-1]);
            }
            row.push_back(1);
            ans.push_back(row);
        }
        return ans;
    }
};