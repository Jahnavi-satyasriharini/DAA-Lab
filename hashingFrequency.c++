#include <iostream>
using namespace std;

int main()
{
    int a[100], freq[101] = {0};
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    cout << "Frequencies:\n";

    for (int i = 0; i < 101; i++)
    {
        if (freq[i] > 0)
            cout << i << " : " << freq[i] << endl;
    }

    return 0;
}