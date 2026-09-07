#include <iostream>
using namespace std;

int maxSum(int a[], int low, int mid, int high){
    int sum = 0;
    int leftSum = a[mid];
    int rightSum = a[mid + 1];

    for (int i = mid; i >= low; i--){
        sum += a[i];

        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++){
        sum += a[i];

        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}

int maxSubarray(int a[], int low, int high){
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSubarray(a, low, mid);
    int right = maxSubarray(a, mid + 1, high);
    int cross = maxSum(a, low, mid, high);

    int result = left;

    if (right > result)
        result = right;

    if (cross > result)
        result = cross;

    return result;
}

int main(){
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Maximum subarray sum = "
         << maxSubarray(a, 0, n - 1);

    return 0;
}