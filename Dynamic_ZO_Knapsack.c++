#include <iostream>
using namespace std;

int main(){
    int n, capacity;
    int w[20], v[20], dp[20][50];

    cout<<"Enter no.of items: ";
    cin>>n;

    cout<<"Enter weights and values:\n";
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    cout<<"Enter knapsack capacity: ";
    cin>>capacity;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= capacity; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i] <= j)
                dp[i][j] = max(v[i] + dp[i-1][j-w[i]],
                               dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    cout<<"Maximum value = " << dp[n][capacity];
    return 0;
}