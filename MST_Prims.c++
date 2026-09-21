#include <iostream>
using namespace std;

int main(){
    int n;
    int graph[100][100];
    int selected[100] = {0};
    int total = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    selected[0] = 1;

    cout << "Edges in MST:\n";

    for (int edges = 0; edges < n - 1; edges++){
    int min = 0;
    int x = 0, y = 0;
    bool found = false;

    for (int i = 0; i < n; i++){
        if (selected[i]){
            for (int j = 0; j < n; j++){
                if (!selected[j] && graph[i][j] != 0){
                    if (!found || graph[i][j] < min){
                        min = graph[i][j];
                        x = i;
                        y = j;
                        found = true;
                    }
                }
            }
        }
    }

    cout << x << " - " << y << " : " << min << endl;

    total += min;
    selected[y] = 1;
}

    cout << "Minimum cost = " << total;

    return 0;
}