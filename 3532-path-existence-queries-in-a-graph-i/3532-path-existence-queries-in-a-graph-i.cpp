class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,1);
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return;
        if(rank[v]>rank[u]){
            rank[v]+=rank[u];
            parent[u]=v;
        }else{
            rank[u]+=rank[v];
            parent[v]=u;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff){
                dsu.unite(i,i-1);
            }
        }
        int Q=queries.size();
        vector<bool> ans;
        for(auto &query:queries){
            int u=query[0];
            int v=query[1];
            if(dsu.find(u)==dsu.find(v)){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
/*
1-2-3 0
*/