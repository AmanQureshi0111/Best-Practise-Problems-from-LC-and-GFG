class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        priority_queue<P,vector<P>,greater<>> pq;
        pq.push({dist[0][0],{0,0}});
        vector<int> dir={-1,0,1,0,-1};
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int len=p.first;
            int x=p.second.first;
            int y=p.second.second;
            for(int d=0;d<4;d++){
                int i=x+dir[d];
                int j=y+dir[d+1];
                if(isValid(i,j,m,n) && dist[i][j]>dist[x][y]+grid[i][j]){
                    dist[i][j]=dist[x][y]+grid[i][j];
                    pq.push({dist[i][j],{i,j}});
                }
            }
        }   
        return dist[m-1][n-1]<health;   
    }
};