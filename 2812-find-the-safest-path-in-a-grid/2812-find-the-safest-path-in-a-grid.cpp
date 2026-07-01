class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<int> dir;
    bool isValid(int i,int j,int n){
        return i>=0 && j>=0 && i<n && j<n;
    }
    bool possible(vector<vector<int>>& grid,int cap,int n){
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        if(grid[0][0]>=cap){
            q.push({0,0});
            vis[0][0]=true;
        }
        while(!q.empty()){
            auto p=q.front(); q.pop();
            int x=p.first;
            int y=p.second;
            for(int d=0;d<4;d++){
                int i=x+dir[d];
                int j=y+dir[d+1];
                if(isValid(i,j,n) && vis[i][j]==false && grid[i][j]>=cap){
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        return vis[n-1][n-1];
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]) return 0;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    pq.push({0,{i,j}});
                    dist[i][j]=0;
                }
            }
        }
        dir={-1,0,1,0,-1};
        while(!pq.empty()){
            auto p=pq.top();
            int md=p.first;
            int x=p.second.first;
            int y=p.second.second;
            pq.pop();
            for(int d=0;d<4;d++){
                int i=x+dir[d];
                int j=y+dir[d+1];
                if(isValid(i,j,n) && dist[i][j]>dist[x][y]+1){
                    dist[i][j]=dist[x][y]+1;
                    pq.push({dist[i][j],{i,j}});
                }
            }
        }
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                low=min(low,dist[i][j]);
                high=max(high,dist[i][j]);
            }
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(dist,mid,n)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};