// LeetCode Problem 240 - https://leetcode.com/problems/search-a-2d-matrix-ii/description/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }