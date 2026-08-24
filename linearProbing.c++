#include <iostream>
using namespace std;

int main(){
    int table[10], n, x;

    for (int i = 0; i < 10; i++){
        table[i] = -1;
    }

    cout << "Enter no.of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> x;
        int index = x % 10;

        while (table[index] != -1){
            index = (index + 1) % 10;
        }
        table[index] = x;
    }

    cout << "Hash Table: ";
    for (int i = 0; i < 10; i++){
        cout << table[i] << " ";
    }
    return 0;
}