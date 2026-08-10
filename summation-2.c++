#include <iostream>
using namespace std;

int sum(int x, int n)
{
    int sum = 0;
    int term = 1;

    for (int i = 0; i <= n; i++)
    {
        sum = sum + term;
        term = term * x;
    }

    return sum;
}

int main()
{
    int x, n;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter n: ";
    cin >> n;

    cout << "Sum = " << sum(x, n);

    return 0;
}