#include <iostream>
using namespace std;

int main()
{
    int table[10], n, x;

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int index = x % 10;
        int j = 1;

        while (table[index] != -1)
        {
            index = (x % 10 + j * j) % 10;
            j++;
        }

        table[index] = x;
    }

    cout << "Hash Table: ";
    for (int i = 0; i < 10; i++)
        cout << table[i] << " ";

    return 0;
}