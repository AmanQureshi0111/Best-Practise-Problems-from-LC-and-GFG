class Solution {
public:
    //BS+TopoSort
    typedef long long ll;
    int n;
    ll bfs(int mid,vector<vector<pair<int,int>>> &adj,vector<int> &topoSort){
        vector<ll> dist(n,LLONG_MAX);
        dist[0]=0;
        for(auto &u:topoSort){
            if(dist[u]<LLONG_MAX){
                for(auto& it:adj[u]){
                    int v=it.first,eW=it.second;
                    if(eW<mid) continue;
                    dist[v]=min(dist[v],dist[u]+eW);
                }
            }
        }
        return dist[n-1];
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int low=0,high=0;
        n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n,0);
        for(auto &edge:edges){
            if(online[edge[0]]==false || online[edge[1]]==false) continue;
            adj[edge[0]].push_back({edge[1],edge[2]});
            high=max(high,edge[2]);
            indegree[edge[1]]++;
        }
        //generate TOPO SORT
        vector<int> topoSort;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u=q.front(); q.pop();
            topoSort.push_back(u);
            for(auto &it:adj[u]){
                int v=it.first;
                if(--indegree[v] ==0) q.push(v);
            }
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            ll sum=bfs(mid,adj,topoSort);
            if(sum<=k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};