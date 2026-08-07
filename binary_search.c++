#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int element)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == element)
            return mid;
        else if (element < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int main()
{
    int n, element;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> element;

    int result = binarySearch(arr, n, element);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}