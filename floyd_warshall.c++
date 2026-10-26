#include <iostream>
using namespace std;

int main(){
    int n, a[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (-1 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][k] != -1 && a[k][j] != -1)
                    if (a[i][j] == -1 ||
                        a[i][k] + a[k][j] < a[i][j])
                        a[i][j] = a[i][k] + a[k][j];

    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}