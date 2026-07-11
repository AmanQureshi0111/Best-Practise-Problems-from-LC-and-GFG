class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return;
        if(size[v]>size[u]){
            size[v]+=size[u];
            parent[u]=v;
        }else{
            size[u]+=size[v];
            parent[v]=u;
        }
    }
    int findS(int x){
        return size[find(x)];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            dsu.unite(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[dsu.find(i)].push_back(i);
        }
        int cnt=0;
        for(auto &it:mp){
            int par=it.first;
            bool flag=true;
            int size=dsu.findS(par);
            for(auto &u:it.second){
                if(adj[u].size()+1!=size){
                    flag=false;
                    break;
                }
            }
            cnt+=flag;
        }
        return cnt;
    }
};