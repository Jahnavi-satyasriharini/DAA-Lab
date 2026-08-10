#include <iostream>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    for (int count = 1; count <= k; count++)
    {
        int minIndex = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
        }

        if (count == k)
            return arr[minIndex];

        arr[minIndex] = 2147483647;
    }

    return -1;
}

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;

    cout << "Kth smallest element = "
         << kthSmallest(arr, n, k);

    return 0;
}