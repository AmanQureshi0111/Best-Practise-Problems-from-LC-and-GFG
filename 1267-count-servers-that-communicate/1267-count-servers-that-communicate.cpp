class DisjointSet{
private:
    vector<int> par,size;
public:
    DisjointSet(int n){
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    int findSize(int x){
        return size[x];
    }
    void Union(int x,int y){
        int xp=find(x);
        int yp=find(y);
        if(xp==yp) return;
        if(size[yp]>size[xp]){
            par[xp]=yp;
            size[yp]+=size[xp];
        }else{
            par[yp]=xp;
            size[xp]+=size[yp];
        }
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        DisjointSet ds(m+n);
        int servers=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(ds.find(i)!=ds.find(j+m)) ds.Union(i,j+m);
                    else servers++;
                }
            }
        }
        int res=0;
        for(int i=0;i<m+n;i++){
            if(ds.find(i)==i && ds.findSize(i)>2){
                res+=ds.findSize(i)-1;
            }
        }
        return servers+res;
    }
};