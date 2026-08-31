#include <iostream>
using namespace std;

int main()
{
    int a[100], bucket[100] = {0};
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements (0-99): ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        bucket[a[i]]++;

    cout << "Sorted array: ";

    for (int i = 0; i < 100; i++)
    {
        while (bucket[i] > 0)
        {
            cout << i << " ";
            bucket[i]--;
        }
    }

    return 0;
}