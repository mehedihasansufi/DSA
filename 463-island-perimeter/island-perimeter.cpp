class Solution {
public:
int n;
int m;
int count;
bool vis[105][105];
vector<pair<int,int>> val={{0,1},{0,-1},{1,0},{-1,0}};
bool valid(int r,int c){
    if(r<0 || r>=n || c<0 || c>=m){
        return false;
    }else{
        return true;
    }
}
void dfs(int si, int sj,vector<vector<int>>& grid){
    vis[si][sj]=true;
    for(int i=0; i<4; i++){
        int ci=si+val[i].first;
        int cj=sj+val[i].second;
       if(valid(ci,cj)==false){
        count++;
       }else if(valid(ci,cj)==true && grid[ci][cj]==0){
        count++;
       }else if(valid(ci,cj)==true && vis[ci][cj]==false && grid[ci][cj]==1){
        dfs(ci,cj,grid);
       }
       
    }
}
    int islandPerimeter(vector<vector<int>>& grid) {
        count=0;
        n=grid.size();
         m=grid[0].size();
        memset(vis,false,sizeof(vis));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==false && grid[i][j]==1){
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};