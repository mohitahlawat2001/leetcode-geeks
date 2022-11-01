class Solution {
public:
  int solve(int i, int j, vector<vector<int>>& grid){
        int n = grid[0].size();
        if(i>=grid.size()) return j;
        
        
        
        if(grid[i][j] == 1 && j + 1 < n && grid[i][j + 1] == 1){
            return solve(i + 1, j + 1, grid);
        }
        
        if(grid[i][j] == -1 && j - 1 >= 0 && grid[i][j - 1] == -1){
            return solve(i + 1, j - 1, grid);
        }
        
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // stores the answer 
        vector<int> fall(n);
        
		// Find the status of each ball -> O(N)
        for(int i = 0; i < n; i++){
            fall[i] = solve(0, i, grid);
        }
        
        return fall;
    }
};