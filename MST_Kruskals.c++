#include <iostream>
using namespace std;

struct Edge{
    int u, v, w;
};

int findParent(int parent[], int x){
    while (parent[x] != x)
        x = parent[x];

    return x;
}

int main(){
    Edge e[100];
    int parent[100];
    int n, m, total = 0, count = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    for (int i = 0; i < m - 1; i++){
        for (int j = i + 1; j < m; j++){
            if (e[i].w > e[j].w){
                Edge temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "Edges in MST:\n";

    for (int i = 0; i < m && count < n - 1; i++){
        int p1 = findParent(parent, e[i].u);
        int p2 = findParent(parent, e[i].v);

        if (p1 != p2){
            cout << e[i].u << " - " << e[i].v
                 << " : " << e[i].w << endl;

            parent[p1] = p2;
            total += e[i].w;
            count++;
        }
    }
    cout << "Minimum cost = " << total;
    return 0;
}