#include <iostream>
using namespace std;

void maxMin(int a[], int low, int high, int &max, int &min){
    if (low == high){
        max = min = a[low];
    }
    else if (high == low + 1){
        if (a[low] > a[high]){
            max = a[low];
            min = a[high];
        }
        else{
            max = a[high];
            min = a[low];
        }
    }
    else{
        int mid = (low + high) / 2;
        int max1, min1, max2, min2;

        maxMin(a, low, mid, max1, min1);
        maxMin(a, mid + 1, high, max2, min2);

        max = (max1 > max2) ? max1 : max2;
        min = (min1 < min2) ? min1 : min2;
    }
}

int main(){
    int a[100], n, max, min;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    maxMin(a, 0, n - 1, max, min);

    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min;

    return 0;
}