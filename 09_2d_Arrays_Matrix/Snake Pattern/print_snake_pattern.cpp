// GFG Problem - https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1
void print(const vector<vector<int>>& mat)
{
    int m = mat.size();  
    int n = mat[0].size(); 

    // Traverse through all rows
    for (int i = 0; i < m; i++) {
        
        // If current row is even, print from left to right
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
        }
        
        // If current row is odd, print from right to left
        else {
            for (int j = n - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
    }
}