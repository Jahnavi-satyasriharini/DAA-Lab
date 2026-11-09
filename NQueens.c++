#include <iostream>
using namespace std;

int a[10][10], n;

bool safe(int row, int col)
{
    for (int i = 0; i < row; i++)
        if (a[i][col] == 1)
            return false;

    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (a[i][j] == 1)
            return false;

    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (a[i][j] == 1)
            return false;

    return true;
}

bool solve(int row)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (safe(row, col))
        {
            a[row][col] = 1;

            if (solve(row + 1))
                return true;

            a[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> n;

    if (n < 1 || n > 10)
    {
        cout << "Enter n between 1 and 10";
        return 0;
    }

    if (solve(0))
    {
        cout << "Solution:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "No solution exists";

    return 0;
}