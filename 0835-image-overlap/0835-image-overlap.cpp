class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
       int M = img1.size(), N = img1[0].size();
        vector<pair<int,int>> A, B;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (img1[i][j]) {
                    A.push_back({i, j});
                }
                if (img2[i][j]) {
                    B.push_back({i, j});
                }
            }
        }
        
        vector<vector<int>> match(2*M, vector<int>(2*N, 0));
        int res = 0;
        for (auto [i, j] : A) {
            for (auto [x, y] : B) {
                res = max(res, ++match[M + i - x][N + j - y]);
            }
        }
        return res;
    }
};