#include <iostream>
using namespace std;

int main(){
    int n, capacity;
    float weight[100], profit[100], ratio[100];
    float total = 0;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++){
        cin >> profit[i];
        ratio[i] = profit[i] / weight[i];
    }
    cout << "Enter capacity: ";
    cin >> capacity;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (ratio[i] < ratio[j]){
                float temp;

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (capacity >= weight[i]){
            total += profit[i];
            capacity -= weight[i];
        }else{
            total += ratio[i] * capacity;
            break;
        }
    }
    cout << "Maximum profit = " << total;
    return 0;
}