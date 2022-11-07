class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
         int ans = 0;
        int nrow = grid.size();
        int ncol = grid[0].size();
        for(int i=0; i<nrow; i++){
        
            for(int j=0; j<ncol; j++){
                
                if(grid[i][j] != 1) continue;
                
                if(i==0 || !grid[i-1][j]) ans++;
                if(i==nrow-1 || !grid[i+1][j]) ans++;
                if(j==0 || !grid[i][j-1]) ans++;
                if(j==ncol-1 || !grid[i][j+1]) ans++;
            }
        }
        
        // hekekke
        return ans;
    }
};