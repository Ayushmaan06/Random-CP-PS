#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<double> prob(n, 0.0);
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    prob[0] = 1.0;
    visited[0] = true;

    double result = 0.0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int count = 0;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                count++;
            }
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                prob[neighbor] = prob[node] / count;
                q.push(neighbor);
            }
        }

        result += prob[node] * weights[node];
    }

    cout << fixed << setprecision(6) << result << "\n";

    return 0;
}
