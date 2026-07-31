#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to check if placing 'val' at board[row][col] is valid
    bool isSafe(vector<vector<char>>& board, int row, int col, int val, int size) {
        char ch = '0' + val;
        for (int i = 0; i < size; i++) {
            // Check row constraint
            if (board[row][i] == ch) return false;
            // Check column constraint
            if (board[i][col] == ch) return false;
            // Check 3x3 subgrid constraint
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
        }
        return true;
    }

    // Aap ki recursive grid traversal approach (row, col)
    int solve(vector<vector<char>>& board, int row, int col, int& size) {
        // Base case: jab columns complete ho jayein, next row par jao
        if (col >= size) {
            row++;
            col = 0;
        }
        
        // Base case: jab sari rows solve ho jayein
        if (row >= size) {
            return 0; // Success
        }

        // Agar cell empty hai ('.')
        if (board[row][col] == '.') {
            for (int i = 1; i <= size; i++) {
                if (isSafe(board, row, col, i, size)) {
                    board[row][col] = '0' + i; // Place character ('1'-'9')
                    
                    if (solve(board, row, col + 1, size) == 0) {
                        return 0; // Solution found!
                    }
                    
                    // Backtrack
                    board[row][col] = '.';
                }
            }
            return -1; // Trigger backtracking
        } 
        else {
            // Cell already filled hai, aage badhein
            return solve(board, row, col + 1, size);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        int size = 9;
        solve(board, 0, 0, size);
    }
};

// Function to print the Sudoku Grid
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // '.' represents empty cells
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solver;
    cout << "--- Unsolved Sudoku ---" << endl;
    printBoard(board);

    solver.solveSudoku(board);

    cout << "\n--- Solved Sudoku ---" << endl;
    printBoard(board);

    return 0;
}
