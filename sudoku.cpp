// sudoku
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> sudoku(9, vector<int>(9, 0));

void printsudoku()
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            for (int j = 0; j < 11; j++)
            {
                if (j == 10)
                {
                    cout << "-";
                    break;
                }
                cout << "--";
            }
            cout << endl;
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                cout << "| ";
            }
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, vector<vector<int>> &sudoku, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == val || sudoku[i][col] == val)
        {
            return false;
        }
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

void removedigits(int n)
{
    vector<vector<int>> visited(9, vector<int>(9, 0));
    while (n != 0)
    {
        int x = rand() % 8;
        int y = rand() % 8;

        if (visited[x][y] == 0)
        {
            sudoku[x][y] = 0;
            visited[x][y] = 1;
            n--;
        }
        n = n;
    }
}

bool solve()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (sudoku[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, sudoku, val))
                    {
                        sudoku[row][col] = val;
                        bool solutionpossible = solve();
                        if (solutionpossible)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void generatepuzzle(int n)
{
    int val = (rand() % 8) + 1;
    sudoku[0][0] = val;
    solve();
    removedigits(n);
    printsudoku();
}

void solvesudoku()
{
    solve();
    printsudoku();
}

int main()
{
    cout << endl
         << endl
         << "-----------------------------SUDOKU-------------------------------------" << endl
         << endl;
    cout << "1. Start" << endl
         << "2. Exit" << endl;
    int n;
    cin >> n;
    cout << endl;
    if (n == 1)
    {
        while (n == 1)
        {
            cout << "Chose difficulty" << endl;
            cout << "1. Easy" << endl
                 << "2. Medium" << endl
                 << "3. Hard" << endl;
            int m;
            cin >> m;
            cout << endl;
            if (m == 1)
            {
                generatepuzzle(41);
            }
            else if (m == 2)
            {
                generatepuzzle(49);
            }
            else if (m == 3)
            {
                generatepuzzle(56);
            }
            cout << endl;
            cout << "1. Solve puzzle" << endl;
            cin >> m;
            cout << endl;
            solvesudoku();
            cout << endl;
            cout << "1. Play again" << endl
                 << "2. Exit" << endl;
            cin >> n;
            cout << endl;
            if (n == 1)
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    cout << endl;
    cout << "----------THANK YOU------------" << endl;
    return 0;
}