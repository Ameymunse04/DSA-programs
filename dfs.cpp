#include <iostream>
using namespace std;

const int n = 5;   
int adj[n][n];
bool visited[n];

void DFS(int v) {
    cout << v << " ";
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    cout << "Enter adjacency matrix for 5 vertices:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int start;
    cout << "Enter starting vertex (0 to 4): ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
