class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color,int initialColor){
        int m = image.size();
        int n = image[0].size();
        if(i<0 || j<0) return;
        if(i>=m || j>=n) return ;
        if(image[i][j]!=initialColor) return ;
        
        image[i][j] = color;
        
        dfs(image,i+1,j,color,initialColor);
        dfs(image,i-1,j,color,initialColor);
        dfs(image,i,j+1,color,initialColor);
        dfs(image,i,j-1,color,initialColor);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor != color){
            dfs(image,sr,sc,color,initialColor);
        }
        return image;
    }
};