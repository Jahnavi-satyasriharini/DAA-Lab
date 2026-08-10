#include <iostream>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    return arr[k - 1];
}

int main()
{
    int n, k;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;

    cout << "Kth smallest element = "
         << kthSmallest(arr, n, k);

    return 0;
}