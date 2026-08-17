#include <iostream>
using namespace std;

void towerOfHanoi(int n)
{
    int totalMoves = 1;

    for (int i = 1; i <= n; i++)
        totalMoves = totalMoves * 2;

    totalMoves = totalMoves - 1;

    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    if (n % 2 == 0)
    {
        char temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    for (int move = 1; move <= totalMoves; move++)
    {
        int disk = 1;

        while (move % (2 * disk) != disk)
            disk++;

        if (disk % 2 == 1)
        {
            cout << "Move disk " << disk << " from "
                 << source << " to " << destination << endl;
        }
        else
        {
            cout << "Move disk " << disk << " from "
                 << auxiliary << " to " << destination << endl;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n);

    return 0;
}