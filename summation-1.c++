#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
        return 1;

    int half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int sum(int x, int n)
{
    if (x == 1)
        return n + 1;

    return (power(x, n + 1) - 1) / (x - 1);
}

int main()
{
    int x, n;

    cout << "Enter variable x: ";
    cin >> x;

    cout << "Enter highest power n: ";
    cin >> n;

    cout << "Sum = " << sum(x, n);

    return 0;
}