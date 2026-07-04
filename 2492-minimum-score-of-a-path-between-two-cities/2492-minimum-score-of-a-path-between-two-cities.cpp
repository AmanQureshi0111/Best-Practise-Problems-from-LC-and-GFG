class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return;
        if(rank[v]>rank[u]){
            parent[u]=v;
            rank[v]+=rank[u];
        }else{
            parent[v]=u;
            rank[u]+=rank[v];
        }
    }
    
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n);
        for(auto &road:roads){
            dsu.unite(road[0]-1,road[1]-1);
        }
        int ans=INT_MAX;
        for(auto &road:roads){
            if(dsu.find(road[0]-1)==dsu.find(0)){
                ans=min(ans,road[2]);
            }
        }
        return ans;
    }
};