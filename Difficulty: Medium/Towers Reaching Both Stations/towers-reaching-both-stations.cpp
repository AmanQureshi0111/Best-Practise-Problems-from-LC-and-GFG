class Solution {
  public:
    int rows,cols;
    bool isValid(int i,int j){
        return i>=0 && j>=0 && i<rows && j<cols;
    }
    void bfs(queue<pair<int,int>> &Q,vector<vector<int>>& mat,vector<vector<bool>>& vis){
        vector<int> dir={-1,0,1,0,-1};
        while(!Q.empty()){
            auto tmp=Q.front(); Q.pop();
            int i=tmp.first;
            int j=tmp.second;
            for(int d=0;d<4;d++){
                int i_=i+dir[d];
                int j_=j+dir[d+1];
                if(isValid(i_,j_) && vis[i_][j_]==false && mat[i_][j_]>=mat[i][j]){
                    vis[i_][j_]=true;
                    Q.push({i_,j_});
                }
            }
        }
    }
    int countCoordinates(vector<vector<int>>& mat) {
        rows=mat.size();
        cols=mat[0].size();
        vector<vector<bool>> stationP(rows,vector<bool>(cols,false));
        vector<vector<bool>> stationQ(rows,vector<bool>(cols,false));
        queue<pair<int,int>> p;
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 || j==0) {
                    p.push({i,j});
                    stationP[i][j]=true;
                }
                if(i==rows-1 || j==cols-1){
                    q.push({i,j});
                    stationQ[i][j]=true;
                }
            }
        }
        bfs(p,mat,stationP);
        bfs(q,mat,stationQ);
        int cnt=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(stationP[i][j] && stationQ[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};