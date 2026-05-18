#include <iostream>
using namespace std;

int board[10][10];
int n;
int solutionCount = 0;

// Check if queen placement is safe
bool isSafe(int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return false;
    }

    // Check right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

// Print board
void printBoard()
{
    cout << "\nSolution " << ++solutionCount << ":\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// Backtracking Function
void solve(int row)
{
    if(row == n)
    {
        printBoard();
        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(isSafe(row, col))
        {
            board[row][col] = 1;

            solve(row + 1);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> n;

    solve(0);

    cout << "\nTotal Solutions: " << solutionCount;

    return 0;
}
