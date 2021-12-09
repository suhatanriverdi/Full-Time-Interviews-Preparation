// Question Link: https://leetcode.com/problems/find-a-peak-element-ii/submissions/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        
        priority_queue<pair<int, vector<int>>> cellsPQ; // { value, { i, j } }
        cellsPQ.push({ mat[0][0], { 0, 0 }}); // Upper-Left Corner
        cellsPQ.push({ mat[0][N - 1], { 0, N - 1 }}); // Upper-Right Corner
        cellsPQ.push({ mat[M - 1][N - 1], { M - 1, N - 1 }}); // Bottom-Left Corner
        cellsPQ.push({ mat[M - 1][0], { M - 1, 0 }}); // Bottom-Right Corner
        
        // 4 directions/neighbors array
        vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        
        while (!cellsPQ.empty()) {
            auto [val, pos] = cellsPQ.top();
            int x = pos[0];
            int y = pos[1];
            cellsPQ.pop();
            
            // If peak is found, return {i, j}
            if (isPeak(x, y, M, N, mat)) {
                return { x, y };
            }
            
            // Mark non-peak cell as -1
            mat[x][y] = -1;
            
            // Check 4 neighbors
            for (vector<int> &direction : directions) {
                int nx = x + direction[0];
                int ny = y + direction[1];
                if (inside(nx, ny, M, N) && mat[nx][ny] != -1) {
                    cellsPQ.push({ mat[nx][ny], { nx, ny } });
                }
            }
        }
        
        return { 1453, 1299 };
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        }
        return true;
    }
    
    bool isPeak(int i, int j, int &M, int &N, vector<vector<int>> &mat) {
        int curVal = mat[i][j];
        int leftVal = (j - 1 >= 0) ? (mat[i][j - 1]) : -1;
        int rightVal = (j + 1 < N) ? (mat[i][j + 1]) : -1;
        int upVal = (i - 1 >= 0) ? (mat[i - 1][j]) : -1;
        int downVal = (i + 1 < M) ? (mat[i + 1][j]) : -1;
        return (curVal > leftVal && curVal > rightVal && curVal > upVal && curVal > downVal);
    }
};