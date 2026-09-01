class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int R=classroom.size();
        int C=classroom[0].size();
        map<pair<int,int>,int> litter_coor_to_idx_map;
        vector<pair<int,int>> litter_item_coord;
        int start_r=-1,start_c=-1;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(classroom[i][j]=='S'){
                    start_r=i;
                    start_c=j;
                }else if(classroom[i][j]=='L'){
                    litter_coor_to_idx_map[{i,j}]=litter_item_coord.size();
                    litter_item_coord.push_back({i,j});
                }
            }
        }
        int total_litters=litter_item_coord.size();
        if(total_litters==0) return 0;
        queue<tuple<int,int,int,int>> q;
        int targeted_mask=(1<<total_litters)-1;
        vector<vector<vector<vector<int>>>> dist(R,vector<vector<vector<int>>>(C,vector<vector<int>>(energy+1,vector<int>(targeted_mask+1,-1))));
        dist[start_r][start_c][energy][0]=0;
        q.push({start_r,start_c,energy,0});
        int dir[]={-1,0,1,0,-1};
        while(!q.empty()){
            auto [r,c,current_e,mask]=q.front(); q.pop();
            int moves=dist[r][c][current_e][mask];
            if(mask==targeted_mask) return moves;
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                if(nr>=0 && nr<R && nc>=0 && nc<C && classroom[nr][nc]!='X'){
                    if(current_e>0){
                        int next_total_moves=moves+1;
                        int energy_after_moves=current_e-1;
                        int new_mask_after_move=mask;
                        char destination_cell_char=classroom[nr][nc];
                        if(destination_cell_char=='L'){
                            int litter_idx=litter_coor_to_idx_map.at({nr,nc});
                            new_mask_after_move|=1<<litter_idx;
                        }
                        if(destination_cell_char=='R'){
                            energy_after_moves=energy;
                        }
                        if(dist[nr][nc][energy_after_moves][new_mask_after_move]==-1 || dist[nr][nc][energy_after_moves][new_mask_after_move]>next_total_moves){
                            dist[nr][nc][energy_after_moves][new_mask_after_move]=next_total_moves;
                            q.push({nr,nc,energy_after_moves,new_mask_after_move});
                        }
                    }
                }
            }
        }
        return -1;
    }
};