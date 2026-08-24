#include <iostream>
using namespace std;

int main()
{
    int a[100], hash[101] = {0};
    int n, T;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target: ";
    cin >> T;

    for (int i = 0; i < n; i++)
    {
        int need = T - a[i];

        if (need >= 0 && need <= 100 && hash[need])
        {
            cout << "Pair found: " << need << " + " << a[i]
                 << " = " << T;
            return 0;
        }

        if (a[i] >= 0 && a[i] <= 100)
            hash[a[i]] = 1;
    }

    cout << "No pair found";

    return 0;
}